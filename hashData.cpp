#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int size = 26;

struct Student{
	char name[50];
	int score;
	int age;
	Student* next;
	Student* prev;
};

Student* hashTable[26];

Student* head[size];
Student* tail[size];

Student* createNewStudent(char name[], int score, int age){
	Student* newStudent = (Student*) malloc(sizeof(Student));
	strcpy(newStudent->name, name);
	newStudent->score = score;
	newStudent->age = age;
	newStudent->next = newStudent->prev = NULL;
	
	return newStudent;
}

int genHashKey(char name[]){
	int index1 = name[0];
	int key;
	
	if(index1 > 96){
		key = (index1 - 97) % size;
		return key;
	}
	key = (index1 - 65) % size;
	return key;
}

void pushMid(Student* insert, int key){
	if(strcmp(head[key]->name, insert->name) > 0){
		insert->next = head[key];
		head[key]->prev = insert;
		head[key] = insert;
		return;
	}else if(strcmp(tail[key]->name, insert->name) < 0){
		insert->prev = tail[key];
		tail[key]->next = insert;
		tail[key] = insert;
		return;
	}
	Student* curr = head[key];
	while(curr->next != NULL && strcmp(curr->next->name, insert->name) < 0){
		curr = curr->next;
	}
	
	insert->next = curr->next;
	insert->prev = curr;
	curr->next   = insert;
	insert->next->prev = curr;
}

void insertHash(char name[], int score, int age){
	int key = genHashKey(name);
	if(hashTable[key] == NULL){
		hashTable[key] = createNewStudent(name, score, age);
	}else{
		int temp = key;
		do{
			temp = (temp + 1) % size;
			if(hashTable[temp] == NULL){
				hashTable[temp] = createNewStudent(name, score, age);
				return;
			}
		}while(temp != key);
		printf("table if full\n");
	}
	
	if(head[key] == NULL){
		head[key] = tail[key] = createNewStudent(name, score, age);
		return;
	}
	pushMid(createNewStudent(name, score, age), key);
	
}

void removeHash(char name[]){
	int key = genHashKey(name);
	
	if(strcmp(hashTable[key]->name, name) == 0){
		free(hashTable[key]);
		hashTable[key] = NULL;
		return;
	}
	int temp = key + 1;
	do{
		temp = (temp + 1) % size;
		if(hashTable[temp] == NULL){
			continue;
		}else if(strcmp(hashTable[temp]->name, name) == 0){
			free(hashTable[temp]);
			hashTable[temp] = NULL;
			return;
		}
	}while(temp != key);
	printf("data not exists");
}

void removeHashChain(char name[]){
	Student* curr;
	int key = genHashKey(name);
	if(head[key] == NULL){
		return;
	}else if(head[key] == tail[key]){
		free(head[key]);
		free(tail[key]);
		head[key] = NULL;
		tail[key] = NULL;
		return;
	} else if(strcmp(head[key]->name, name) == 0){
		curr = head[key];
		head[key] = curr->next;
		curr->next = NULL;
		head[key]->prev = NULL;
		free(curr);
		curr = NULL;
		return;
	} else if(strcmp(tail[key]->name, name) == 0){
		curr = tail[key];
		tail[key] = curr->prev;
		curr->prev = NULL;
		tail[key]->next = NULL;
		free(curr);
		curr = NULL;
		return;
	}
	
	curr = head[key];
	whie(curr != NULL && strcmp(curr->name, name) != 0){
		curr = curr->next;
	}
	if(curr == NULL){
		return;
	}
	
	Student* before = curr->prev;
	Student* after = curr->next;
	before->next = after;
	after->prev = before;
	curr->prev = NULL;
	curr->next = NULL;
	free(curr);
	curr = NULL;
}

void printChain(){
	for(int i=0; i<size; i++){
		printf("%d. ", (i+1));
		if(head[i] != NULL){
			Student* curr = head[i];
			while(curr != NULL){
				printf("Name: %s, score: %d, age: %d ->", curr->name, curr->score, curr->age);
			}
		}
		puts("");
	}
}

void printAll(){
	for(int i=0; i<size; i++){
		printf("%d. ", (i+1));
		if(hashTable[i] != NULL){
			printf("Name: %s, score: %d, age: %d", hashTable[i]->name, hashTable[i]->score, hashTable[i]->age);
		}
		printf("\n");
	}
}



int main(){
	insertHash("Asep", 85, 16);
	insertHash("Wahyu", 90, 17);
	printAll();
	return 0;
}
