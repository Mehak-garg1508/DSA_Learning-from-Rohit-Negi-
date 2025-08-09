// Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]


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
  int arr[5] = {1,2,3,4,5};
  Node *head = createLL(arr,0,5);
 cout << "Input: ";
 print(head);
 cout << endl;

 int k = 2;
 int count = 0;
 Node *temp = head;
 while(temp){
  count++;
  temp = temp->next;
 }
 count = count - k;
 if(count == 0){
  temp = head;
  head = head->next;
  delete temp;
  cout << "Null LL";
  // print(head);
 }
 temp = head;
 Node *prev = NULL;
 while(count--){
  prev = temp;
 temp = temp->next;
 }
 prev->next = temp->next;
 delete temp;
 print(head);
}