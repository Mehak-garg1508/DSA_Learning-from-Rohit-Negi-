// Given the head a linked list, the task is to reverse every k 
// node in the linked list. If the number of nodes is not a multiple 
// of k then the left-out nodes in the end,
//  should be considered as a group and must be reversed.

// Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
// Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

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
  int arr[8] = {1,2,2,4,5,6,7,8};
  Node *head = createLL(arr,0,8);
 cout << "Input: ";
 print(head);
 cout << endl;

 int k = 4;
 Node *first = new Node(0);
 first->next = head;
 head = first;
 while(first->next){
  Node *second = first->next;
  Node *prev = first;
  Node *curr = second;
  int x = k;
  while(x && curr){
  Node *front = curr->next;
  curr->next = prev;
  prev = curr;
  curr = front;
  x--;
  }
  first->next = prev;
  second->next = curr;
  first = second;
 }
 first = head;
 head = head->next;
 delete first;
 cout << "Output is:" << " " ;
 print(head);
}