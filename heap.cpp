#include<stdio.h>
#include<stdlib.h>

const int max = 1000;
int heap[max];
int heap_size = 0;
void swap(int a, intb){
 int temp = *a;
 a =b;
 b = temp;
}

int parent(int idx){
 return (idx-1)/2;
}

int leftChild(int idx){
 return 2idx+1; //parent of the index
}

int rightChild(int idx){
 return 2*idx+2;
}

int assert(int parentIndex, int childIndex){
 return heap[childIndex] > heap[parentIndex];
}

void upHeap(int idx){
 if(idx<=0){
  return;
 }
 int parentIdx = parent(idx);
 if(!assert(parent(idx), idx)){
  swap(&heap[idx], &heap[parentIdx]);
  upHeap(parentIdx);
 }
}

void insert(int value){
 heap[heap_size] = value;
 upHeap(heap_size);
 heap_size+=1;
}

//pops the top ost element(root
//which is also the smallest/largest value

//idx is the parent
void downHeap(int idx){
 if(idx >= heap_size){
  return;
 }
 //find the smallest of the parent and its two children
 int rep = idx;
 int leftIdx = leftChild(idx);
 int rightIdx = rightChild(idx);
 
 if(leftIdx < heap_size && !assert(rep, leftIdx)){
  rep = leftIdx;
 }
 if(rightIdx < heap_size && !assert(rep, rightIdx)){
  rep = rightIdx;
 }
 if(rep != idx){
  swap(heap+rep, heap+idx);
  downHeap(rep);
 }
}

int del(){
 int temp = heap[0];
 heap[0] = heap[--heap_size];
 downHeap(0);
 
 return temp;
}

void inOrder(int idx, int tabs){
 if(idx>=heap_size){
  return;
 }
 //only for visualization
 inOrder(rightChild(idx), tabs+1);
 for(int i=0; i<tabs; i++){
  printf("\t");
 }
 printf("%d\n", heap[idx]);
 inOrder(leftChild(idx), tabs+1);
}

void print(){
 inOrder(0,0);
 puts("=============================================");
 
}

int main()
{
 insert(20);
 print();
 insert(5);
 print();
 insert(30);
 print();
 
 while(heap_size > 0){
  printf("Popped: %d\n", del());
  print();
 }
 
 return 0;
}
