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

b_tree create_btree(int *nodelist, int position)
{
	b_tree newnode;

	if (nodelist[position] == 0|| position > 7)
		return NULL;

	else
	{
		newnode = (b_tree) malloc (sizeof(treenode));

		newnode->left = create_btree(nodelist, 2 * position);

		newnode->data = nodelist[position];

		newnode->right = create_btree(nodelist, (2 * position) + 1);
	}

	return newnode;
}

void inorder(b_tree point)
{
	if (point != NULL)
	{
		inorder(point->left);
		printf("%c", point->data);
		inorder(point->right);
	}
}

void preorder(b_tree point)
{
	if (point != NULL)
	{
		printf("%c", point->data);
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
		printf("%c", point->data);
	}
}

void main()
{
	b_tree root = NULL;

	int nodelist[8] = {' ','+','*','/','4','8','6','2'};
	root = create_btree(nodelist, 1);
	
	inorder(root);
	printf("\n\n");
	
	preorder(root);
	printf("\n\n");

	postorder(root);
	printf("\n\n");
}