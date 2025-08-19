// Remove Duplicates from a Sorted Linked List

// Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists).
// Note: Try not to use extra space. The nodes are arranged in a sorted way.

#include <iostream>
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
  int arr[6] = {2,2,2,3,3,4};
  Node *head = createLL(arr,0,6);
 cout << "Input: ";
 print(head);
 cout << endl;

 Node *prev = head;
 Node *curr = head->next;
 Node *future;
 while(curr!=NULL){
  future = curr->next;
  if(prev->data == curr->data){
    delete curr;
    prev->next = future;
  }
  else{
  prev = curr;
  }
  curr = future;
 }
 cout << "Output:" << endl;
 print(head);
}