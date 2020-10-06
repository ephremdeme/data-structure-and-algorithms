#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}node;

node *createList(){
	node *head=NULL,*temp,*prev=NULL;
	int data,num;
	printf("Enter the number of nodes: ");
	scanf("%d",&num);
	while(num--){
		printf("Enter the data: ");
		scanf("%d",&data);
		node *newNode = (node *)malloc(sizeof(node));
		newNode->prev=NULL;
		newNode->next=NULL;
		newNode->data=data;
		if(!head){
			head = newNode;
			temp=head;
		}else{
			temp->next = newNode;
			newNode->prev=temp;
			temp=newNode;
		}
	}
	return head;
}
void displayList(node *head){
	node *temp = head;
	if(temp){
		printf("%d ",temp->data);
		displayList(temp->next);
	}
}
void insertNodeEnd(node *head){
	node *temp = head;
	int data;
	printf("Enter the data: ");
	scanf("%d",&data);
	while(temp->next){
		temp=temp->next;
	}
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=temp;
	temp->next=newNode;
}
void insertNodeMid(node *head, int pos){
	node *temp = head;
	node *newNode = (node *)malloc(sizeof(node));
	int data;
	printf("Enter the data: ");
	scanf("%d",&data);
	newNode->data = data;
	pos-=2;
	while(pos--){
		temp=temp->next;
	}
	newNode->prev=temp;
	newNode->next=temp->next;
	temp->next=newNode;
}

int main(){
	node *head=NULL;
	head = createList();
	displayList(head);
	printf("\n");
	//insertNodeEnd(head);
	insertNodeMid(head,4);
	displayList(head);
	printf("\n");
	return 0;
}
