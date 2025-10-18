#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;



node* insert(node *head)
{
    node *node_add;
    node *bkp_head=head;
    printf("enter data");
    int data;
    scanf("%d",&data);
    node_add=(node *)malloc(sizeof(node));
    node_add->data=data;
    node_add->next=NULL;
    if(head==NULL)
    {
        head=node_add;
        return head;
    }
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=node_add;
    
    return bkp_head;
}
node *delete(node *head)
{
    node *head_bkp=head;
    node *previous=head;
    int data=0;
    printf("enter node you want to delete\n");
    scanf("%d",&data);
    if(head->data==data)
    {
        previous=head->next;
        free(head);
        head_bkp=previous;
        return head_bkp;
    }

    while(head->next!=NULL)
    {
        previous=head;
        head=head->next;
        if(head->data ==data)
        {
            previous->next=head->next;
            free(head);
            break;
        }
    }
    return head_bkp;
}
node *display(node *head)
{
    node *head_bkp=head;
    if(head==NULL)
        return head;
    while(head->next!=NULL)
    {
        printf("%d==>",head->data);
        head=head->next;
    }
    printf("%d=====>",head->data);
    return head_bkp;
}
node *reverse(node *head)
{
    //node *head_bkp=head;
    node *new_head=head;
    node *second=head;
    node *remaining=head;

    if(head==NULL)
    return head;
    //first pass
    second=new_head->next;
    remaining=second->next;

    new_head->next=NULL;
    second->next=new_head;
    new_head=second;

    if(remaining!=NULL)
    while(remaining->next!=NULL)
    {
        second=remaining;
        remaining=remaining->next;

        second->next=new_head;
        new_head=second;
    }
    if(remaining->next==NULL)
    {
        remaining->next=new_head;
        new_head=remaining;
    }
    return new_head;
}

int main()
{
    node *head=NULL;
    int choice=0;
    while(1)
    {
    printf("1) insert \t 2)delete \t 3)display \t 4)reverse \t 5)exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        head=insert(head);
        break;
        case 2:
        head=delete(head);
        break;
        case 3:
        head=display(head);
        break;
        case 4:
        head=reverse(head);
        break;
        case 5:
        exit(0
        );
    }
    }

}