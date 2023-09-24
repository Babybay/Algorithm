#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char nim[15];
	char nama[50];
	float ipk;
};

struct tnode{
	struct student data;
	struct tnode *next;
};

struct tnode *head=NULL,*tail=NULL;
 
void pushBelakang(struct student data)
{
	struct tnode *newnode=(struct tnode*)malloc(sizeof(struct tnode));
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL){
		head=newnode;
	}
	else
	{
		//buat pointer untuk menelusuri linked list mulai dari head
		struct tnode *curr=head;
		//cari node terakhir, node terakhir adalah node yg nextnya NULL
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		//taruh data baru di belakang node terakhir
		curr->next=newnode;
	}
	
}

void pushTail(struct student data)
{
	struct tnode *newnode=(struct tnode*)malloc(sizeof(struct tnode));
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL){
		head=tail=newnode;
	}
	else
	{
		tail->next=newnode;
		tail=newnode;
	}
	
}

void viewList(){
	
	struct tnode *curr=head;
	
	while(curr!=NULL)
	{
		printf("%s %s %f\n",
			curr->data.nim,curr->data.nama,curr->data.ipk);
			
		curr=curr->next;
	}
	
}

void deleteNode(char *nim)
{
	struct tnode *curr=head;
	if(strcmp(head->data.nim,nim))
	{
		head=head->next;
		free(curr);
	}
	else{
		
		while(curr!=NULL && strcmp(curr->next->data.nim,nim)!=0)
		{
			curr=curr->next;
		}
		if(curr!=NULL){
			struct tnode *temp=curr->next;
			curr->next=temp->next;
			free(temp);	
		}
		else{
			puts("Data not found");
		}

	}
	
}



int main(){
	int menu;
	
	do{
		puts("============================");
		puts("SUNIB Restaurant Reservation");
		puts("============================");
		puts("Waiting Line:");
		puts("");
		puts("1. Add Customer to Queue");
		puts("2. Serve One");
		puts("3. Serve All");
		puts("4. Dismiss All");
		puts("0. Exit");
		printf("Input Menu Number: ");
		scanf("%d",&menu);
		struct student data;
		switch(menu){
			case 1: 
				printf("Input nim:");
				scanf("%s",data.nim);
				printf("Input nama:");
				scanf("%s",data.nama);
				printf("Input ipk:");
				scanf("%f",&data.ipk);
				
				pushBelakang(data);break;
			case 2: 
					char nim[15];
					printf("Input nim:");
					scanf("%s",nim);
					deleteNode(nim);
					break;
			case 3: viewList();
		}
			
	}while(menu!=4);

	
	
	return 0;
}
