// Remove every kth node
// Given a singly linked list, your task is to remove every kth node from the linked list. 

// Input: Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 2
// Output: 1 -> 3 -> 5 -> 7

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
  int arr[8] = {1,2,3,4,5,6,7,8};
  int k = 2;
  Node *head = createLL(arr,0,8);
 cout << "Input: ";
 print(head);
 cout << endl;
 if(k == 1)
 cout << "Null List" << endl;
 Node *curr = head;
 Node *prev = NULL;
 int count = 1;
 while(curr){
  if(count == k){
  prev->next = curr->next;
  delete curr;
  curr = prev->next;
  count = 1;
  }
  else{
    count++;
    prev = curr;
    curr=curr->next;
  }
 }
 cout << "Output: ";
 print(head);
}