#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node * prev;
	int data;
	struct node * next;
};
int main()
{
	// Initializing the required variables.
	int l,p;
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *temp;
	struct node *t;
	struct node *v;
	struct node *r;
	
	// Scanning elements from the user and then making a linked list with them.
	printf("Enter the number of elemnets to be present: \n");
	scanf("%d",&l);
	for(int j = 0;j<l;j+=1)
	{
		if(j==0)
		{
			scanf("%d\n",&head->data);
			head->next = NULL;
			head->prev = NULL;
			temp = head;
		}
		else
		{
			t = (struct node *)malloc(sizeof(struct node));
			scanf("%d",&t->data);
			t->next = NULL;
			t->prev = temp;
			temp->next = t;
			temp = t;	
		}
	}

	// Code to add an element at the beginning.
	printf("Enter the element to be added at the beginning of the linked list:\n");
	t = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&t->data);
	t->next = head;
	t->prev = NULL;
	head->prev = t;
	head = t;

	// Code to add an element at the end.
	printf("Enter the element to be added at the end of the linked list:\n");
	t = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&t->data);
	t->next = NULL;
	t->prev = temp;
	temp->next = t;
	temp = t;	
 	
	// Code to add an element at any position.
	printf("Enter the element to be added at any position of the linked list:\n");
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
		t->prev = v;
		t->next = temp;
		temp->prev = t;	
	}
	else if(p==l+1)
	{
		v->next = t;
		t->prev = v;
		t->next = temp;
	}
	else
	{
		t->next = temp;
		t->prev = NULL;
		temp->prev = t;
		head = t;
	}
	
	// Code for deleting any element from the linked list.
	struct node *cmo = NULL;
	struct node *cpo = head;
	struct node *c = NULL;
	printf("Enter the position of the element to be removed:\n");
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
		c->prev = NULL;
		free(c);
	}
	else if(c->next == NULL)
	{	
		cmo->next = NULL;
		c->prev = NULL;
		free(c);
	}
	else
	{
		cmo->next = cpo;
		cpo->prev = cmo;
		c->next = NULL;
		c->prev = NULL;
		free(c);
	}
	
	// Printing the elements from: first to last.
	temp = head;
	for(int j = 1;j<=l+2;j+=1)
	{
		if(j==l+2)
		{
			r = temp;
		}
		printf("%d\n",temp->data);
		temp = temp->next;		
	}
	
	// Printing the elements from: last to first.
	temp = r;
	for(int j = 1;j<=l+2;j+=1)
	{
		printf("%d\n",temp->data);
		temp = temp->prev;		
	}
	return 0;
}
