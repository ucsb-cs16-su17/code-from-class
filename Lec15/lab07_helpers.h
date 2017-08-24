#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

struct LinkedList {
  Node *head;
  Node *tail;
};

#define ASSERT_EQUALS(expected,actual) assertEquals(expected,actual,#actual)
LinkedList * arrayToLinkedList(int *a, int size);
string intToString(int i);
string linkedListToString(LinkedList *list);
void freeLinkedList(LinkedList * list);
void assertEquals(string expected, string actual, string message);
