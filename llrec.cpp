#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************



void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
  smaller = nullptr; 
  larger = nullptr; 

  if (!head) {
    return;
  }
  // Node* cur = head;
  Node* next;
  Node* lastSmaller = nullptr;
  Node* lastLarger = nullptr;

  // while (head != NULL){
    next = head->next;
    if (head->val <= pivot) {
      smaller = head;
      llpivot(next, smaller->next, larger, pivot);    
    }
    else {
      larger = head;
      llpivot(next, smaller, larger->next, pivot); 
    }

    // head->next = nullptr;
    head = nullptr;
  // }
}