#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int value; 
    Node *next, *prev; 
}*head, *tail;

Node *createNode(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value; 
    newNode->next = newNode->prev = NULL; 
    return newNode; 
}

void pushHead(int value){
    Node *newNode = createNode(value); 
    if(head == NULL){
        head = tail = newNode; 
        return; 
    }

    head->prev = newNode; 
    newNode->next = head; 
    head = newNode; 
}

void pushMid(int value){
    Node *newNode = createNode(value); 
    Node *curr = head; 
    if(head->value > value){
        pushHead(value);
        return;
    }
    if(tail->value < value){
        pushTail(value); 
        return; 
    }
    while(curr != NULL){
        if(curr->value > value){
            curr->prev->next = newNode; 
            newNode->prev = curr->prev; 
            curr->prev = newNode; 
            newNode->next = curr; 
        }
        curr = curr->next; 
    }
}

void pushTail(int value){
    Node *newNode = createNode(value); 
    if(head == NULL){
        head = tail = newNode; 
        return; 
    }

    tail->next = newNode;
    newNode->prev = tail; 
    tail = newNode; 
}

void popHead(int value){
    if(head == NULL){
        return; 
    }
    if(head == tail){
        free(head); 
        head = tail = NULL; 
        return; 
    }
    Node *temp = head; 
    head = temp->next; 
    head->prev = NULL; 
    free(temp); 
}

void popTail(int value){
    if(tail == NULL){
        return; 
    }
    if(head == tail){
        free(head); 
        head = NULL;
        tail = NULL; 
        return; 
    }
    Node *temp = tail; 
    tail = tail->prev; 
    tail->next = NULL;
    free(tail); 
}

void printList(){
    Node *curr = head; 
    printf("NULL");
    while(curr != NULL){
        printf("<-[ %d ]->", curr->value);
        curr = curr->next; 
    }
    printf("NULL\n");
}

int main(){

    pushHead(5);
    printList();

    pushHead(3); 
    printList(); 

    pushHead(7); 
    printList(); 

    return 0; 
}
