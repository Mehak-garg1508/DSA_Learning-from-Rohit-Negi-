
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
  int arr[5] = {1,2,3,2,1};
  Node *head = createLL(arr,0,5);
 cout << "Input: ";
 print(head);
 cout << endl;

 int count = 0;
 Node *temp = head;
 while(temp){
  count++;
  temp = temp->next;
 }

 count = count/2;

Node *curr = head;
Node *prev = NULL;
while(count--){
  prev = curr;
  curr = curr->next;
}
prev->next = NULL;

Node *front = NULL;
prev = NULL;
while(curr){
  front = curr->next;
  curr->next = prev;
  prev = curr;
  curr = front;
}

bool isPalidrome = 1;

Node *head1 = head;
Node *head2 = prev;
while(head1){
  if(head1->data != head2->data){
    isPalidrome = 0;
    break;
  }
  else{
    head1 = head1->next;
    head2 = head2->next;
  }
}
if(isPalidrome){
  cout << "Linked List is Palidrome";
}
else{
  cout << "Not a palidrome";
}
}