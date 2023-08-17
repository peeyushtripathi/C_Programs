#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int data;;
	struct tree *left;
	struct tree *right;
}tree;


void insert_at_appropriate_location(tree *root_tracer,tree *node)
{
	if(root_tracer->data >node->data)
	{
		if(root_tracer->left !=NULL)
			insert_at_appropriate_location(root_tracer->left, node);
		else
			root_tracer->left=node;
	}
	else if(root_tracer->data <node->data)
	{
		if(root_tracer->right !=NULL)
			insert_at_appropriate_location(root_tracer->right, node);
		else
			root_tracer->right=node;
	}
}

tree *insert_tree(tree *root)
{
	int number_input=0;
	printf("enter elements one by one\n");
	printf("put -99 to stop\n");
	while(1)
	{

		scanf("%d",&number_input);
		if(number_input==-99)
			break;
		else
		{
			tree *node=(tree *)malloc(sizeof(tree));
			node->data=number_input;
			node->left=NULL;
			node->right=NULL;
 			if(root==NULL)
				root=node;
			else
				insert_at_appropriate_location(root,node);

		}
	}
	return root;
}

void inorder(tree *root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	printf("==%d==>",root->data);
	inorder(root->right);
}
void preorder(tree *root)
{
	if(root==NULL)
		return ;
	printf("==%d==>",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(tree *root)
{
	if(root==NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	printf("==%d==>",root->data);
}

int main()
{
	tree *root=NULL;
	while(1)
	{
		printf("1 insert \t 2 inorder \t 3 preorder \t 4 postorder \t 5 exit");
		int choise=0;
		scanf("%d",&choise);
		switch(choise)
		{
			case 1:
				root=insert_tree(root);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				exit(0);;
				break;
			default:
				printf("try again\n");
		}
	}	
	return 0;
}
