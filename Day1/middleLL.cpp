// Middle of the Linked List
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
// Input: head = [1,2,3,4,5]
// Output: [3]
// Explanation: The middle node of the list is node 3.

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

 int count = 1;
 Node *temp = head;
 while(temp){
  count++;
  temp = temp->next;
 }
 count = count/2;
 temp = head;
 while(count--){
 temp = temp->next;
 }
 cout << "Middle element: " << temp->data;
}