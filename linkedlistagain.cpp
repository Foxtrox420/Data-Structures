#include<stdio.h>
#include<stdlib.h>
//link list

struct Node{
	 int val;
	 Node* next;
}*head = NULL, *tail = NULL;


Node* makeNode(int val){
	Node* newNode = (Node*)malloc(sizeof(Node*));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void pushHead(int val){
	 Node* newNode = makeNode(val);
	 if(head==NULL){
	  head=newNode;
	  tail=newNode;
	 }else{
	  newNode->next = head;
	  head = newNode;
	 }
}

void pushTail(int val){
	 Node *newNode = makeNode(val);
	 if(head == NULL){
	  head = newNode;
	  tail = newNode;
	 }else{
	  tail->next = newNode;
	  tail = newNode;
	 }
}

void pushMid(int val){
	if(head == NULL || val <= head->val){
		pushHead(val); 
	}
	else if(val >= tail->val){
		pushTail(val); 
	}
	else{
		Node* curr = head; 
		Node* newNode = makeNode(val); 
		while(curr->next != NULL){
			if(curr->next->val >= val){
				newNode->next = curr->next; 
				curr->next = newNode; 
				return; 
			}
			curr = curr->next;
		}
	}
}

void popHead(){
	if(head == NULL){
		return; 
	}
	else if(head == tail){
		free(head);
		head = NULL; 
		tail = NULL; 
	}
	else{
		Node* temp = head->next;
		free(head);
		head = temp; 
	}
}

void popTail(){
	if(tail == NULL){
		return; 
	}
	else if(head == tail){
		free(head);
		head = NULL;
		tail = NULL; 
	}
	else{
		Node* curr = head; 
		while(curr != NULL){
			if(curr->next == tail){
				curr->next = NULL; 
				free(tail);
				tail = curr;
				return; 
			}
			curr = curr->next;
		}
	}
}

void popMid(int val){
	if(head == NULL){
		return; 
	}
	else if(val == head->val){
		popHead();
	}
	else if(val != head->val){
		popTail(); 
	}
	else{
		Node* curr = head; 
		while(curr->next !=NULL){
			if(curr->next->val == val){
				Node* temp = curr->next->next;
				free(curr->next); 
				curr->next = temp; 
				return; 
			}
			curr = curr->next;
		}
	}
}

void search(int val){
	Node* curr = head; 
	while(curr != NULL){
		if(curr->val == val){
			printf("%d is found in the list\n",val);
			return; 
		}
		curr = curr->next; 
	}
	printf("%d is not found in the list\n",val); 
}

void print(){
 Node* curr = head;
 while(curr!=NULL){
  printf("%d ->", curr->val);
  curr = curr->next;
 }
 printf("NULL\n");
 if(head!=NULL){
  printf("Head: %d\n", head->val);
 }
 if(tail!=NULL){
  printf("Tail : %d\n", tail->val);
 }
}

int main()
{
// pushHead(5);
// print();
// pushHead(7);
// print();
// 
// pushTail(4);
// print();
// pushTail(8);
// print();

pushMid(6);  print();
pushMid(2);  print();
pushMid(3);  print();
pushMid(10); print();
pushMid(7);  print();
popTail();   print();

 
 return 0;
}
