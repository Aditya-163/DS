#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
int main()
{
	int i;
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the number of elemnets to be present: \n");
	scanf("%d",&i);
	for(int j = 0;j<i;j+=1)
	{
		if(j==0)
		{
			scanf("%d\n",&head->data);
			head->next = NULL;
			temp = head;
		}
		else
		{
			struct node *t = (struct node *)malloc(sizeof(struct node));
			scanf("%d",&t->data);
			t->next = NULL;
			temp->next = t;
			temp = t;	
		}
	}
	temp = head;	
	for(int j = 0;j<i;j+=1)
	{
		printf("%d\n",temp->data);
		temp = temp->next;		
	}	
	return 0;
}
