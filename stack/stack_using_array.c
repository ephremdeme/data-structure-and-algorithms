/* A basic Stack implementation in C using Array, with the following functionalities implemented:
	-Push operation 
	-Pop operation
	-Display stack


	This implementation is done for max 100 elements only, you can increase it for changing the value of MAX
*/

#include<stdio.h>
#define MAX 100

//Push operation in the stack , which inserts the elements in the stack
void push(int data,int *stack, int *top){
	if(*top==MAX-1){                          // Condition for, Stack is full
		printf("\nSTACK OVERFLOW\n");
		return;
	}
	stack[++(*top)] = data;
}

//Pop operation in the stack , whitch delete the elements from the stack
int pop(int *top, int *stack){
	if(*top==-1){                             // Condition for, Stack is empty    
		printf("\nSTACK UNDERFLOW\n");
		return -1;
	}
	return stack[(*top)--];
}

//Display Stack
void displayStack(int *stack,int top){
	while(top>=0){                       
		printf("%d ",*(stack+top)); 
		--top;
	}
	printf("\n");
}
int main(){
	int stack[MAX];    // Array
	int top=-1;
	push(1,stack,&top);
	push(2,stack,&top);
	push(3,stack,&top);
	push(5,stack,&top);
	displayStack(stack,top);
	int data = pop(&top,stack);
	data = pop(&top,stack);
	displayStack(stack,top);
	
	return 0;
}
