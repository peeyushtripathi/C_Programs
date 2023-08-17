#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char *ptr;
	struct node *next;
}node;

node* push(node *head, char *ptr)
{
	node *element= (node *)malloc(sizeof(node));
	element->ptr=ptr;
	element->next=NULL;
	if(head==NULL)
		head=element;
	else
	{
		element->next=head;
		head=element;
	}
	return head;

}

node* pop(node *head)
{
	if(head==NULL)
	{
		printf("underflow");
        }
	else if(head->next!=NULL)
	{
		printf("element is %s\n",head->ptr);
		node *dummyhead=head;
		head=head->next;
		free(dummyhead);
	}
	else
	{
		printf("element is %s\n",head->ptr);
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
			int i=0;
		while(1)
		{
			if(iterator->ptr[i]==' ' || iterator->ptr[i]=='\0')
				break;
			else
			{
				printf("%c",iterator->ptr[i]);
				i++;
			}
		}
		if(iterator->next!=NULL)
			iterator =iterator ->next;
		else
			break;
		printf("\n");
	}
	return head;
}

int main()
{
	char *ptr="I LOVE INDIA";
	int i=0;
	node *head=NULL;
	head=push(head,&ptr[i]);
	while(ptr[i]!='\0')
	{
		if(ptr[i+1]==' ')
			head=push(head,&ptr[i+2]);
		i++;
	}
	head=display(head);
	return 0;
}
