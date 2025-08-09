// Given the head of a linked list, rotate the list to the right by k places.
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

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
  k = k % count;
  if(k == 0){
    print(head);
  }
  count = count - k;
  temp = head;
  Node *prev = NULL;
  while(count--){
    prev = temp;
   temp = temp->next;
  }
  prev->next = NULL;
  Node *temp2 = temp;
  while(temp2->next){
    temp2 = temp2->next;
  }
  temp2->next = head;
  head = temp;
  cout << "Output is: ";
  print(head);
}