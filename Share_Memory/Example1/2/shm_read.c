/* Filename: shm_read.c */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct DNode DNode;
typedef struct DList DList;

#define MAX_DNODE 32            // Max. domain string length
#define MAX_DLEN 64             // Max. number of list nodes
#define SHM_KEY 0x1234

#define DNULL (MAX_DLEN + 1)    // NULL value

struct DNode {
    char domain[64];
    char val[2];
    size_t next;
};

struct DList {
    DNode pool[MAX_DNODE];      // fixed-size space for nodes
    size_t npool;               // used space in pool
    size_t pfree;               // pointer to re-use freed nodes
    size_t head;                // global list head
};

DList *dlist;

DNode *dnode_alloc(void)
{
    if (dlist->pfree != DNULL) {
        DNode *node = dlist->pool + dlist->pfree;

        dlist->pfree = dlist->pool[dlist->pfree].next;
        return node;
    } else {
        if (dlist->npool < MAX_DNODE) return &dlist->pool[dlist->npool++];
    }

    return NULL;
}

void dnode_free(DNode *node)
{
    if (node) {
        node->next = dlist->pfree;
        dlist->pfree = node - dlist->pool;
    }
}

DNode *dnode(size_t index)
{
    return (index == DNULL) ? NULL : dlist->pool + index;
}

DNode *dnode_next(const DNode *node)
{
    return dnode(node->next);
}

DNode *dnode_push(size_t *head, const char *str, const char *val)
{
    DNode *node = dnode_alloc();

    if (node) {
        strncpy(node->domain, str, sizeof(node->domain));
        strncpy(node->val, val, sizeof(node->val));
        node->next = *head;
        *head = node - dlist->pool;
    }

    return node;
}

void dnode_pop(size_t *head)
{
    if (*head != DNULL) {
        size_t next = dlist->pool[*head].next;

        dnode_free(&dlist->pool[*head]);
        *head = next;
    }
}


int main(int argc, char *argv[]) {
   int shmid;
   struct shmseg *shmp;
   shmid = shmget(SHM_KEY, sizeof(struct DList), IPC_CREAT | 0660);
   if (shmid == -1) {
      perror("Shared memory");
      return 1;
   }
   
   // Attach to the segment to get a pointer to it.
   dlist = shmat(shmid, NULL, 0);
   if (dlist == (void *) -1) {
      perror("Shared memory attach");
      return 1;
   }
   
    while (dlist->head != DNULL) {
        puts(dnode(dlist->head)->domain);
        puts(dnode(dlist->head)->val);
        dnode_pop(&dlist->head);
    }
    
   printf("Reading Process: Reading Done, Detaching Shared Memory\n");
   
   if (shmdt(dlist) == -1) {
      perror("shmdt");
      return 1;
   }
   printf("Reading Process: Complete\n");
   return 0;
}


/*
 * Ref:
 * https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_shared_memory.htm?fbclid=IwAR3RAHgVagRyYE0gdQqEx4V1em2r2cV43xgduKhQsU49V8xMwDWDxgxGt_k
 */
