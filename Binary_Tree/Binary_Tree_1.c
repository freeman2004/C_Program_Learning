#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct tree
{
	struct tree *left;
	char data;
	struct tree *right;
};

typedef struct tree treenode;
typedef treenode *b_tree;


b_tree insert_node(b_tree root, int node)
{
	b_tree newnode;
	b_tree currentnode;
	b_tree parentnode;
	
	newnode = (b_tree) malloc (sizeof(treenode));
	
	newnode->left = NULL;
	newnode->data = node;
	newnode->right = NULL;
	
	if (root == NULL)
	{
		return newnode;
	} else {
		currentnode = root;
		while (currentnode != NULL)
		{
			parentnode = currentnode;
			if(currentnode->data > node)
				currentnode = currentnode->left;
			else
				currentnode = currentnode->right;
		}
		if(parentnode->data > node)
			parentnode->left = newnode;
		else
			parentnode->right = newnode;
	}
	
	return root;
}

b_tree create_btree(int *data, int len)
{
	int i ;
	b_tree root = NULL;
	
	for (i = 0; i < len; i++)
	{
		//printf("%d ",data[i]);
		root = insert_node(root, data[i]);
	}
	
	return root;
}

void inorder(b_tree point)
{
	if (point != NULL)
	{
		inorder(point->left);
		printf("%d ", point->data);
		inorder(point->right);
	}
}

void preorder(b_tree point)
{
	if (point != NULL)
	{
		printf("%d ", point->data);
		preorder(point->left);
		preorder(point->right);
	}
}

void postorder(b_tree point)
{
	if (point != NULL)
	{
		postorder(point->left);
		postorder(point->right);
		printf("%d ", point->data);
	}
}

void main()
{
	b_tree root = NULL;
	
	int i, index = 0;
	int value;
	int nodelist[20];
	
	printf("please input (0:terminal)> \n\n");
	
	scanf("%d", &value);
	
	while (value != 0)
	{
		nodelist[index] = value;
		index = index + 1;
		scanf("%d", &value);
	}
	
	root = create_btree(nodelist, index);

    printf("inorder \n\n");
	inorder(root);
	printf("\n\n");

    printf("preorder \n\n");	
	preorder(root);
	printf("\n\n");

    printf("postorder \n\n");
	postorder(root);
	printf("\n\n");

}