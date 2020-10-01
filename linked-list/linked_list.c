//AN IMPROVED IMPLEMENTATION OF LINKED LISTS WITH SEPARATE FUNCTIONS FOR OPERATIONS//
#include<stdio.h>
#include<stdlib.h>
struct node{
	int i;
	struct node *next;
};
struct node *insertNodeEnd(struct node*, int);
struct node *insertNodeBeg(struct node*, int);
struct node *insertAfter(struct node*, int,int);
struct node *deleteNode(struct node*, int);
struct node *reverseList(struct node *head);
void displayList(struct node*);
void deleteList(struct node*);

int main(){
	struct node* head = NULL; //HEADER FOR LIST
	int n,data;
	printf("Enter the number of nodes you want to create: ");
	scanf("%d",&n);
	while(n--){
		printf("Enter the data: ");
		scanf("%d",&data);
		head = insertNodeEnd(head,data);
	}
	//head = insertNodeBeg(head,100);
	//displayList(head);
	//head = insertAfter(head,3,89);
	displayList(head);
	//head = deleteNode(head,5);
	head = reverseList(head);
	displayList(head);
	deleteList(head);
	return 0;
}

struct node *insertNodeEnd(struct node* head,int data){
	struct node* temp,p;
	temp = head;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->i = data;
	newNode->next = NULL;
	if(head==NULL){
		head = newNode;	
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = newNode;
	}
	return head;
}
struct node *insertNodeBeg(struct node *head, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->next = head;
	newNode->i = data;
	head = newNode;
	return head;
}
struct node *insertAfter(struct node *head, int pos, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	struct node *temp = head;
	newNode->i = data;
	int i =0;
	while(i<(pos-1)){
		temp = temp->next;
		i++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return head;
}
void displayList(struct node* head){
	struct node* temp;
	temp = head;
	if(temp!=NULL){
		printf("%d -> ",temp->i);
		displayList(temp->next);
	}
}
void deleteList(struct node *head){
	struct node *temp;
	while(head->next!=NULL){
		temp = head;
		free(temp->next);
		head = head->next;
	}
	free(head->next);
}
struct node *deleteNode(struct node* head, int pos){
	struct node *temp = head;
	struct node *pp = NULL;
		////// IF 1st node is deleted
	if(pos==1){
		head = head->next;
		free(temp);
	}else{
		int i = 0;
		while(i<(pos-2)){
			temp=temp->next;	
			i++;
		}
		if((temp->next)->next != NULL){
			pp = (temp->next)->next;
			free(temp->next);
			temp->next = pp;
		}else{
			free(temp->next);
			temp->next = NULL;
		}
	}	
	return head;
}
struct node *reverseList(struct node *curr){
	struct node *prev = NULL, *nextNode = NULL;
	while(curr){
		nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
	}
	return prev;
}