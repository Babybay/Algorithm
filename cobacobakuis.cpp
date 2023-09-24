#include <stdio.h>
#include <stlib.h>
#include <string.h>

struct Customer{
	char name[50];
	int age;
	char ticketClass[20];
	float days;
};

struct Ticket{
	int first;
	int business;
	int economy;
};

struct Tnode{
	struct Customer data;
	struct TnodeTicket data;
	struct Tnode *next;
};

struct Tnode *head=NULL, *tail=NULL;

void pushDepan(struct Customer data, struct TnodeTicket data){
	struct Tnode *newnode=(struct *tnode)malloc(sizeof(struct tnode));
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct tnode *curr=head;
		
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = newnode;
	}
}

void pushBelakang(struct Customer data, struct TnodeTicket data){
	struct Tnode *newnode=(struct *tnode)malloc(sizeof(struct tnode));
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		tail->next=newnode;
		tail=newnode;
	}
}

int main(){
	
	return 0;
}
