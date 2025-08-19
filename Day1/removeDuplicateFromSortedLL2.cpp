// Remove Duplicates from a Sorted Linked List

// Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists).
// Note: Try not to use extra space. The nodes are arranged in a sorted way.

// Input:
// LinkedList: 2->2->4->5
// Output: 2 -> 4 -> 5
// Explanation: In the given linked list 2 -> 2 -> 4 -> 5, only 2 occurs more than 1 time. So we need to remove it once.

#include <iostream>
#include<vector>
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

 vector<int>ans;
 ans.push_back(head->data);
 Node* curr = head->next;
 while(curr != NULL){
 if(ans[ans.size() - 1] != curr->data){
  // what two elements are eqaul or an element is dublicate
  ans.push_back(curr->data);
 }
 curr = curr->next;
 }
 curr = head;
 Node *prev = NULL;
 for(int i = 0; i < ans.size(); i++){
  curr->data = ans[i];
  prev = curr;
  curr = curr->next;
 }
 prev->next = NULL;
 
 cout << "Output is: " << endl;
 print(head);
}