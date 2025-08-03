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

void print(Node *curr){
while(curr){
  cout << curr->data << " ";
  curr = curr->next;
}
}

int main(){
  int arr[5] = {1,2,3,4,5};
  int size = 5;
  // Insertion at starting
  Node *head = NULL;
  for(int i = 0; i < size; i++){
    if(head == NULL){
      head = new Node(arr[i]);
    }
    else{
    Node *temp = new Node(arr[i]);
    temp->next = head;
    head = temp;
    }
  }
cout << "Printing the linked list (insertion at start)" << endl;
print(head);

// Insetion at ending
}