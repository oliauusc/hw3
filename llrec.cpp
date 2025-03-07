#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************



void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
  smaller = nullptr; 
  larger = nullptr; 

  if (!head) return;

  // Node* cur = head;
  Node* next;
  Node* lastSmaller = nullptr;
  Node* lastLarger = nullptr;

  while (head != NULL){
    next = head->next;
    if (head->val <= pivot) {
      if (!smaller) smaller = head;
      else {
        lastSmaller->next = head;
      }
      lastSmaller = head;
  }
    else {
      if (!larger) larger = head;
      else {
        lastLarger->next = head;
      }
      lastLarger = head;

    }

    head->next = nullptr;
    head = next;
  }
}