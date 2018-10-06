#include<stdio.h>
#include<stdlib.h>

struct node{

	int key;
	struct node *next;
	struct node *prev;

};

struct node* insert(int key,struct node* head){

	struct node* temp=(struct node*)malloc(sizeof(struct node)); 
	temp->key=key;
	temp->next=head;
	temp->prev=NULL;

	if(head!=NULL){
		head->prev=temp;
	}
	head=temp;
	return head;
}

struct node* delete(struct node* head,struct node* del){

	if(head==NULL||del==NULL)
		return head;
	
	if(del==head)
		head=del->next;
	
	if(del->next!=NULL)
		del->next->prev=del->prev;

	if(del->prev!=NULL)
		del->prev->next=del->next;

	free(del);

	return head;
}

struct node* del_all(struct node* head){

	int i=0;
	struct node* temp=head;
	
	while(temp!=NULL){
		temp=delete(temp,temp);
	}

	return temp;
}


void print(struct node* head){

	struct node* temp=head;
	
	while(temp!=NULL){

		printf("%d", temp->key);
		temp=temp->next;
	}

}
