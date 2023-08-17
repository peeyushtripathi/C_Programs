#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node* insert(node *head)
{
	int data;
	node *iterator=head;;
	printf("enter element");
	scanf("%d",&data);
	node *element= (node *)malloc(sizeof(node));
	element->data=data;
	element->next=NULL;
	if(head==NULL)
		head=element;
	else
	{
		while(iterator->next!=NULL)
			iterator=iterator->next;
		iterator->next=element;
	}
	return head;

}

node* delete(node *head)
{
	if(head==NULL)
	{
		printf("underflow");
        }
	else if(head->next!=NULL)
	{
		printf("element is %d",head->data);
		node *dummyhead=head;
		head=head->next;
		free(dummyhead);
	}
	else
	{
		printf("element is %d",head->data);
		free(head);
		head=NULL;
	}
	return head;
}

node* display(node *head)
{
	node *iterator =head;
	while(iterator!=NULL)
	{
		printf("==> %d",iterator->data);
		if(iterator->next!=NULL)
			iterator =iterator ->next;
		else
			break;
	}
	return head;
}

int main()
{
	node *head=NULL;
	int choise =0;
	while(1)
	{
		printf("1) inqueue \t 2) dequeue \t 3) display \t 4) exit");	
		scanf("%d",&choise);
		switch (choise)
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
				exit(0);
				break;
			default:
			printf("invalid input\n");
		}
	}

	return 0;
}
