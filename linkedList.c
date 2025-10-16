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
	printf("enter element");
	scanf("%d",&data);
	node *element= (node *)malloc(sizeof(node));
	element->data=data;
	element->next=NULL;
	if(head==NULL)
		head=element;
	else
	{
		node *iterator=head;
		while(iterator->next !=NULL)
			iterator= iterator->next;
		iterator->next=element;
	}
	return head;

}

node* delete(node *head)
{
	int data=0;
	node *iterator=head;
	node *previous=head;
	printf("enter node you want to delete");
	scanf("%d",&data);
	if(head==NULL)
		printf("empty list\n");
	if(iterator->data==data)
	{
		head=iterator->next;
	}
	else
	{
		while(iterator->next !=NULL && iterator->data !=data)
		{
			previous=iterator;
			iterator= iterator->next;
		}
		if(iterator->data ==data)
		{
			//if last element matches
			if(iterator->next ==NULL)
			{
				free(previous->next);
				previous->next=NULL;
			}
			//for intermediate
			else if(iterator->next !=NULL)
			{
				previous->next=iterator->next;
				free(iterator);
			}
		}
		else
		{
			printf("element not present in list\n");
		}

		
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


node* reverse(node *head)
{
	node *new_head=head;
	node *ptr2=head;
	node *ptr3=head;

	ptr2=ptr2->next;
	ptr3=ptr2->next;
	new_head->next=NULL;
	ptr2->next=new_head;
	new_head=ptr2;

	while(ptr3->next!=NULL)
	{
		ptr2=ptr3;
		ptr3=ptr3->next;  //counter
		ptr2->next=new_head;
		new_head=ptr2;
	}
	if(ptr3->next==NULL)
	{
		ptr3->next=new_head;
		new_head=ptr3;
	}

	while(new_head->next!=NULL)
	{
		printf("%d==",new_head->data);
		new_head=new_head->next;
	}
	return ptr3;
}

int main()
{
	node *head=NULL;
	int choise =0;
	while(1)
	{
		printf("1) insert \t 2) delete \t 3) display \t 4) exit \t 5) reverse");	
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
			case 5:
				head=reverse(head);
				break;
			default:
			printf("invalid input\n");
		}
	}

	return 0;
}
