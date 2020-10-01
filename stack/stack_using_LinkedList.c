/* A basic Stack implementation in C using linkedlist, with the following functionalities implemented:
	-Push operation 
	-Pop operation
	-Display stack
*/

#include<stdio.h>
#include<stdlib.h>

// Node, the basic data structure in single linkedlist
typedef struct node{
	int data;
	struct node *next;
}node;

//Push operation in the stack , which inserts the elements in the stack
void push(node **top, int data){
	node *newNode = (node *)malloc(sizeof(node));
	if(!newNode){                        // Condition for, Stack is full
		printf("\nSTACK OVERFLOW! HEAP FULL\n");
		return;
	}
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
}

//Pop operation in the stack , whitch delete the elements from the stack
int pop(node **top){
	if(!*top){                          // Condition for, Stack is empty
		printf("\nSTACK UNDERFLOW\n");
		return 0;
	}
	node *temp = *top;
	*top = (*top)->next;
	int data = temp->data;
	free(temp);                         // Free up the memory
	return data;
}

//Display Stack
void displayStack(node *head){
	node *temp = head;
	if(temp){
		printf("%d ",temp->data);
		displayStack(temp->next);
	}
}
int main(){
	node *stack=NULL;
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	push(&stack,5);
	displayStack(stack);
	printf("\n");
	int data = pop(&stack);
	displayStack(stack);
	printf("\n");
	return 0;
}
