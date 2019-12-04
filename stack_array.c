#include<stdio.h>
#include<stdlib.h>
struct stack{
	int *p;
	int capacity;
	int top;
	int prevCap;
};
void stackRecreate(struct stack *s)
{
	int c = 2*(s->capacity);
	int *p = (int *)malloc(sizeof(int)*c);
	for(int j =0;j<s->capacity;j+=1)
	{
		*(p+j) = *(s->p+j);
	}
	s->p = p;
	s->prevCap = s->capacity;	
	s->capacity = c;
}
int pop(struct stack *s)
{
	s->top-=1;
	return *(s->p+(s->top)+1);
}
void push(int element,struct stack *s)
{
	s->top+=1;
	*(s->p+(s->top)) = element;
}
int peek(struct stack *s)
{
	return *(s->p+(s->top));
}
int isEmpty(struct stack *s)
{
	if(s->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull(struct stack *s)
{
	if(s->top == (s->capacity)-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	struct stack *s;
	int e;
	s->top = -1;
	s->prevCap = 0;
	printf("Enter the capactiy of the stack:\n");
	scanf("%d",&s->capacity);
	s->p = (int *)malloc((s->capacity)*(sizeof(int)));
	printf("Enter the elements:\n");
	for(int j=1;j<=s->capacity;j+=1)
	{
		scanf("%d",&e);
		push(e,s);
	}

	printf("Getting the top element of the stack:\n");
	printf("%d\n",peek(s));

	printf("Is the stack empty:\n");
	printf("%d\n",isEmpty(s));

	printf("Is the stack full:\n");
	printf("%d\n",isFull(s));
	
	stackRecreate(s);
	printf("%d: This is the new capacity\n",s->capacity);
	printf("Enter the new elements:\n");
	for(int j=1;j<=s->prevCap;j+=1)
	{
		scanf("%d",&e);
		push(e,s);
	}
	printf("Getting the top element of the stack:\n");
	printf("%d\n",peek(s));
	// Printing all the elements:
	for(int j=1;j<=s->capacity;j+=1)
	{
		printf("%d\n",pop(s));
	}
	printf("The position of the top pointer is: %d\n",s->top);
	return 0;
}
