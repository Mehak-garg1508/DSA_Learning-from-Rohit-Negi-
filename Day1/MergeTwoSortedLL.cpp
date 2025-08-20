// Merge two sorted linked lists
// Given the head of two sorted linked lists consisting of nodes respectively. 
// The task is to merge both lists and return the head of the sorted merged list.

// Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
// Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40

#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;
Node(int value){
  data = value;
  next = NULL;
}
};

Node *createLL(int arr[], int index, int size){
if(index == size){
  return NULL;
}
Node *temp = new Node(arr[index]);
temp->next = createLL(arr,index + 1,size);
return temp;
}


void print(Node *head){
  while(head != NULL){
    cout << head->data << " ";
    head = head->next;
  }
}

int main(){
  int arr1[4] = {5,10,15,40};
  int arr2[3] = {2,3,20};
  Node *head1 = createLL(arr1,0,4);
  Node *head2 = createLL(arr2,0,3);
 cout << "Input1: ";
 print(head1);
 cout << endl;
cout << "Input2: ";
 print(head2);
 cout << endl;

Node *head = new Node(0);
Node *tail = head;
while(head1 && head2){
if(head1->data <= head2->data){
  tail->next = head1;
  tail = tail->next;
  head1 = head1->next;
  tail->next = NULL;
}
else{
  tail->next = head2;
  tail = tail->next;
  head2 = head2->next;
  tail->next = NULL;
}
} 
if(head1){
  tail->next = head1;
  tail = tail->next;
}
if(head2){
  tail->next = head2;
  tail = tail->next;
}
tail = head;
head = head->next;
delete tail;
print(head);
}