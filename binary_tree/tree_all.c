#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    struct node *left;
    struct node *right;
}tree;

typedef struct queue{
    struct tree *element;
    struct tree *behind;

}queue;
queue *myqueue=NULL;
tree* insert(tree *root)
{
    tree *root_bkp=root;
    tree *pptr=root;
    tree *new_node=(tree *)malloc(sizeof(tree));
    printf("enter data:");
    scanf("%d",&new_node->data);
    if(root==NULL)
        {
            new_node->left=NULL;
            new_node->right=NULL;
            root=new_node;
            return root;
        }
    while(root!=NULL)
    {
        if(root->data >new_node->data)
        {
            pptr=root;
            root=root->left;
        }
        else if(root->data<new_node->data)
        {
            pptr=root;
            root=root->right;
        }
        else
        {
            printf("data already present");
            return root_bkp;
        }
    }
    if(root==NULL)
    {
        if(pptr->data >new_node->data)
        {
            pptr->left=new_node;
        }
        else
        pptr->right=new_node;
    }

    return root_bkp;
}

tree* delete(tree *root)
{
    return root;
}
void display_options(tree *root)
{
    int choice;
    printf("1) inorder \t 2) preorder \t 3) postorder 4) levelorder");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        inorder(root);
        break;
        case 2:
        preorder(root);
        break;
        case 3:
        postorder(root);
        break;
        case 4:
        levelorder(root);
        break;
    }
}
void preorder(tree *root)
{
    if(root==NULL)
        return 0;
    else
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(tree *root)
{
    if(root==NULL)
        return 0;
    else
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}


void postorder(tree *root)
{
    if(root==NULL)
        return 0;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void enqueue(tree *node)
{
    queue *tmp=myqueue;
    if(tmp==NULL)
    {
        queue *newentry=(queue *)malloc(sizeof(queue));
        newentry->element=node;
        newentry->behind=NULL;
        myqueue=newentry;
    }
    else{
        while(tmp->behind!=NULL)
        {
            tmp=tmp->behind;
        }

        queue *newentry=(queue *)malloc(sizeof(queue));
        newentry->element=node;
        newentry->behind=NULL;
        tmp->behind=newentry;
    }
}

tree* dequeue()
{
    queue *tmp=myqueue;
    if(tmp==NULL)
    {
        return tmp;
    }
    else{
        myqueue=myqueue->behind;
    }
    return tmp->element;
}

void levelorder(tree *root)
{
    if(root==NULL)
        return 0;
    else
    {
        printf("%d",root->data);
        if(root->left !=NULL)
            enqueue(root->left);
        if(root->right!=NULL)
            enqueue(root->right);

        levelorder(dequeue());
        //display(root->left);
        //display(root->right);
    }
}

int main()
{
    int choice;
    tree *root=NULL;
    while(1)
    {
        printf("1)insert \t 2) delete \t 3) display \t 4) exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            root=insert(root);
            break;
            case 2:
            root=delete(root);
            break;
            case 3:
            display_options(root);
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}