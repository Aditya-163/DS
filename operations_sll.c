#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
int main()
{
	int l,p;
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *temp;
	struct node *t;
	struct node *v;
	printf("Enter the number of elemnets to be present: \n");
	scanf("%d",&l);
	for(int j = 0;j<l;j+=1)
	{
		if(j==0)
		{
			scanf("%d\n",&head->data);
			head->next = NULL;
			temp = head;
		}
		else
		{
			t = (struct node *)malloc(sizeof(struct node));
			scanf("%d",&t->data);
			t->next = NULL;
			temp->next = t;
			temp = t;	
		}
	}
	// Code to add an element at the beginning.
	printf("Enter the element to be added at the beginning of the linked list:\n");
	t = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&t->data);
	t->next = head;
	head = t;

	// Code to add an element at the end.
	printf("Enter the element to be added at the end of the linked list:\n");
	t = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&t->data);
	t->next = NULL;
	temp->next = t;
	temp = t;	 

	// Code to add an element at any position.
	printf("Enter the element at any position of the linked list:\n");
	t = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&t->data);
	printf("At what position should it be put?\n");
	scanf("%d",&p);
	v = NULL;
	temp = NULL;
	for(int j=1;j<=p;j+=1)
	{
		if(j==1)
		{
			temp = head;
		}
		else
		{
			v = temp;
			temp = temp->next;	
		}	
	}
	if((v!=NULL)&&(p!=l+1))
	{
		v->next = t;
		t->next = temp;	
	}
	else if(p==l+1)
	{
		t->next = temp;
		v->next = t;
	}
	else
	{
		t->next = temp;
		head = t;
	}
	// Code for deleting any element from the linked list.
	struct node *cmo = NULL;
	struct node *cpo = head;
	struct node *c = NULL;
	printf("Enter the position of the element ot be removed:\n");
	scanf("%d",&p);
	for(int j=1;j<=p;j+=1)
	{
		if(j==1)
		{
			c = head;
			cpo = cpo->next;
		}
		else if(j==2)
		{
			cmo = head;
			c = c->next;
			cpo = cpo->next;
		}	
		else
		{
			cmo = cmo->next;
			c = c->next;
			cpo = c->next;
		}
	}
	if(c == head)
	{
		head = cpo;
		c->next = NULL;
		free(c);
	}
	else if(c->next == NULL)
	{	
		cmo->next = NULL;
		free(c);
	}
	else
	{
		cmo->next = cpo;
		c->next = NULL;
		free(c);
	}
	// Printing the elements.
	temp = head;
	for(int j = 0;j<l+2;j+=1)
	{
		printf("%d\n",temp->data);
		temp = temp->next;		
	}	
	return 0;
}
