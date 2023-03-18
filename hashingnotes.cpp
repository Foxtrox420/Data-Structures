#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node{
	char ID[6]; //ST001 
	char name[30]; 
	int age; 
	Node* next; 
};

struct linkedList{
	Node* head; 
	Node* tail; 
};

int inc = 1;

Node* createNode(char name[], int age){
	Node* newNode = (Node*) malloc(sizeof(Node)); 
	strcpy(newNode->name,name); 
	newNode->age = age; 
	//random
//	sprintf(newNode->ID,"ST%03d",1+(rand()%100));
	//incremental e.x ST001, ST002, ST003...
	sprintf(newNode->ID,"ST%03d", inc++);
	newNode->next = NULL; 
	return newNode;  
}

const int MAX_ELEMENT = 10; 

Node* hashTable[10]; // head of the linked list  

void prepTable(){
	for(int i = 0; i < MAX_ELEMENT; i++){
		hashTable[i] = NULL; 
	}
}

//ASCII Hashing 
int hashing(char str[]){
	int ret = 0;
	for(int i = 0; i < strlen(str); i++){
		ret += str[i]; 
	}
	return ret % MAX_ELEMENT; 
}

void insert(char name[], int age){
	Node* newNode = createNode(name, age); 
	int idx = hashing(newNode->ID); 
	
	//linked list part 
	if(hashTable[idx] == NULL){
		hashTable[idx] = newNode; 
	}
	else{
		Node* curr = hashTable[idx];
		while(curr != NULL){
			if(curr->next == NULL){
				curr->next = newNode; 
				return;
			}
			curr = curr->next; 
		}
	}
}

void print(){
	
	for(int i = 0; i < MAX_ELEMENT; i++){ 
		printf("%d: ", i); 
		Node* curr = hashTable[i];
		while(curr != NULL){
			printf("(%s): %s, %d --->", curr->ID, curr->name, curr->age);
			curr = curr->next; 
		}
		printf("NULL\n"); 
	}
}

void pop(char id[]){
	int idx = hashing(id); 
	
	// hashtable 
	// popmid
	
	if(hashTable[idx] == NULL){
		return;
	}
	else if(strcmp(hashTable[idx]->ID, id) == 0){
		Node* temp = hashTable[idx]->next; 
		free(hashTable[idx]);
		hashTable[idx]  = temp; 
	}
	else{
		Node* curr = hashTable[idx]; 
		while(curr->next != NULL){
			if(strcmp(curr->next->ID, id) == 0){
				Node* temp = curr->next->next; 
				free(curr->next); 
				curr->next = temp; 
				return; 
			}
			curr = curr->next; 
		}	
	}
	
}

void popAll(){
	for(int i = 0; i < MAX_ELEMENT; i++){
		Node* curr= hashTable[i]; 
		while(curr != NULL){
			Node* temp = curr->next; 
			free(curr); 
			curr = temp; 
		}
		hashTable[i] = NULL; 
	}
}

// search by key 
Node* searchID(char id[]){
	int idx = hashing(id);
	
	// linked list code
	Node* curr = hashTable[idx]; 
	while(curr != NULL){
		if(strcmp(curr->ID, id) == 0){
			return curr; 
		}
		curr = curr->next; 
	}
	return NULL; 
}

// search by member variabes
Node* searchName(char name[]){
	for(int i = 0; i < MAX_ELEMENT; i++){
		Node* curr = hashTable[i]; 
		while(curr != NULL){
			if(strcmp(curr->name, name) == 0){
				return curr; 
			}
			curr = curr->next; 
		}
	}

	return NULL; 
}

void printTidy(){
	for(int i = 0; i < MAX_ELEMENT; i++){ 
		printf("%d: ", i); 
		Node* curr = hashTable[i];
		while(curr != NULL){
			printf("(%s): %s, %d --->", curr->ID, curr->name, curr->age);
			curr = curr->next; 
		}
		printf("NULL\n"); 
	}
}

int main(){
	
	prepTable(); 
	insert("test", 5);
	insert("test", 5);
	insert("test", 5);
	insert("test", 5);
	print(); 
	pop("ST002"); 
	printf("\n");
	print();
	
// This is for the incremental
//	srand(time(NULL)); 
//	Node* a = createNode("test", 5); 
//	printf("%s\n", a->ID);
//	a = createNode("test", 5); 
//	printf("%s\n", a->ID);
	return 0; 
}
