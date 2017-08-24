#include <iostream>
#include <string>
#include "lab07_helpers.h"
using namespace std;

//Precondition: A pointer to a LinkedList object created on the heap
//Postcondition: Delete all occurrences of nodes with the given value
//Use an iterative solution (loops)
void deleteNodeIteratively(LinkedList *list, int value) {
  // nothing to do if list is empty
  if (list->head == NULL) return;

  // find the new head
  Node *newHead = list->head;
  // delete from the head while the data == value
  // watch out--newHead might be NULL
  while (newHead != NULL && newHead->data == value) {
    Node *oldHead = newHead;
    newHead = newHead->next;
    delete oldHead;
  }

  // did we clear out the entire list doing this?
  if (newHead == NULL) {
    list->head = NULL;
    list->tail = NULL;
    return;
  }

  // now we know the list isn't empty, and the new head 
  // does *not* need to be deleted anymore

  // iterate starting one after the new head
  Node *prev = newHead;
  Node *cur = newHead->next;
  while (cur != NULL) {
    // define next inside the loop so that we know 
    // that cur != NULL
    Node *next = cur->next;
    
    // if cur == value, delete it
    if (cur->data == value) {
      delete cur;
      prev->next = next;

      // pretend the old cur never existed
      cur = prev;
    }

    // iterate
    prev = cur;
    cur = cur->next;
  }

  // when the loop ends, cur will be NULL, so prev is the new tail
  Node *newTail = prev;

  list->head = newHead;
  list->tail = newTail;
}

int main() {

  int fourNums[]={12,24,36,36};
  
  LinkedList *list = arrayToLinkedList(fourNums,4);
  ASSERT_EQUALS( "[12]->[24]->[36]->[36]->null", linkedListToString(list));
  
  deleteNodeIteratively(list, 36);
  assertEquals( "[12]->[24]->null",linkedListToString(list),"iterative delete: list after deleting 36");
  
  deleteNodeIteratively(list, 12);
  assertEquals( "[24]->null",linkedListToString(list),"iterative delete: list after deleting 24");
  
  deleteNodeIteratively(list, 12);
  assertEquals( "[24]->null",linkedListToString(list),"iterative delete: list after attempting to delete value that doesn't exist in the list");
  
  deleteNodeIteratively(list, 24);
  assertEquals( "null",linkedListToString(list),"iterative delete: list after deleting last node");
  
  deleteNodeIteratively(list, 12);
  assertEquals( "null",linkedListToString(list),"iterative delete: attempting to delete from an empty list");
  
  freeLinkedList(list);

  return 0;
}
