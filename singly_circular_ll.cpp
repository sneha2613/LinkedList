//Insert a node at the end of the Circular LL

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *head=NULL;
node *last=NULL;

node *createNode(){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}

/*void insert(){
	node *temp;
	temp=createNode();
	printf("\nEnter the data: ");
	scanf("%d",&temp->data);
	if(head==NULL){
			head=temp;
			temp->next=head;
	}
	else{
		node *ref;
		ref=head;
		while(ref->next!=head){
			ref=ref->next;
		}
		ref->next=temp;
		temp->next=head;
	}
	printf("\nSuccessfully inserted Data.");
}*/

void insertAtEnd(){
	node *temp=createNode();
	printf("\nEnter a data for Last Position: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(last==NULL){
		last=temp;
		last->next=last;
	}
	else{
		temp->next = last->next;
		last->next=temp;
		last=last->next;
	}
	printf("\nSuccessfully inserted Data.");
}

void insertAtBegin(){
	node *temp=createNode();
	printf("\nEnter a data for First Position: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(last==NULL){
		last=temp;
		last->next=last;
	}
	else{
		temp->next = last->next;
		last->next=temp;
		
	}
	printf("\nSuccessfully inserted Data.");
}

/*void traverseUsingHead(){
	if(head==NULL){
		printf("\nNo Data is present");
		return ;
	}
	printf("\nData present in the List:\n");
	node *ref=head;
	do{
		printf("\t%d",ref->data);
		ref=ref->next;
	}
	while(ref!=head);
}*/



void traverseUsingLast_Pointer(){
	if(last==NULL){
		printf(" ");
		return;
	}
	node *ref=last->next;
	do{
		printf("\n\t%d",ref->data);
		ref=ref->next;
	}
	while(ref!=last->next);
}



void deleteAtBegin(){
	node *del;
	printf("\nAfter deletion the List is: ");
	if(last->next==last){
		del=last;
		last=NULL;
	}
	else{
		del= last->next;
		last->next=last->next->next;
		free(del);
		
	}
}

int main(){
//	insert();
//	insert();
	insertAtEnd();
	insertAtBegin();
//	traverseUsingHead();
	traverseUsingLast_Pointer();
	deleteAtBegin();
	traverseUsingLast_Pointer();
	return 0;
}
