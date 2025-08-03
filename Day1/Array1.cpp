// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// // Note: If it is not possible to allocate books to all students, return -1.

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113

#include<iostream>
using namespace std;

int main(){
  int arr[4] = {12,34,67,90};
  int k = 2;

  int start = 0;
  int end = 0;
  int ans = -1;
  int n = 4;
  for(int i = 0; i < n; i++){
    start = max(start,arr[i]);
    end += arr[i];
  }
  while(start<=end){
    int mid = start + (end - start)/2;
    int page = 0;
    int count = 1;
    for(int i = 0; i<n; i++){
      page+=arr[i];
      if(page>mid){
        page = arr[i];
        count++;
      }
    }
    if(count <= k){
      ans = mid;
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
  }
  cout << "Minimumed maximum number of pages assigned to students are:  "<< ans << endl;
}