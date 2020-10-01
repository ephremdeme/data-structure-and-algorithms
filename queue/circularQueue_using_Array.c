#include<stdio.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int data){
	rear = (rear+1)%MAX;
	if(front==rear){
		printf("\nQUEUE OVERFLOW\n");
		if(rear==0)	rear = MAX-1;
		else	rear = rear-1;
		return;
	}
	if(front==-1)	front=0;
	queue[rear]=data;
}
int dequeue(){
	if(front==-1){
		printf("\nQUEUE UNDERFLOW! NO ITEMS IN THE QUEUE\n");
		return -1;
	}
	int data = queue[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}else{
		front = (front+1)%MAX;
	}
	return data;
}
void printQueue(){
	int temp = front;
	if(temp==-1){
		printf("\nLMAO! NOTHING TO DISPLAY\n");
		return;
	}
	if(rear>=temp){
		while(temp<=rear){
			printf("%d ",queue[temp]);
			++temp;
		}
	}else{
		if(temp>rear){
			while(temp<MAX){
				printf("%d ",queue[temp]);
				++temp;
			}
			temp=0;
			while(temp<=rear){
				printf("%d ",queue[temp]);
				++temp;
			}
		}
	}
	printf("\n");
}
int main(){
	int num,data;
	printf("How many items you want to add in the queue?");
	scanf("%d",&num);
	while(num--){
		printf("Enter the data: ");
		scanf("%d",&data);
		enqueue(data);
	}
	printQueue();
	data = dequeue();
	printf("\nData dequeued is: %d\n",data);
	printQueue();
	return 0;
}
