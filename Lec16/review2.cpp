#include <iostream>
using namespace std;

// 9. Passing arrays to functions and returning arrays 
// from functions

// return a new array on the heap, that is twice the size of 
// the input array
// the given array is repeated twice in the new array
int* array_twice(int arr[], int size) {
    int *new_arr = new int[size*2];

    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
        new_arr[i+size] = arr[i];
    }

    return new_arr;
}

// 10. Pointers

void pointers() {
    int x;
    int *p = &x; // p holds the *memory address* of x

    *p = 5; // x is now 5 because x and *p are linked together
    cout << x << endl;
}

// 11. Structs

/*

Structs help you keep track of a group of related variables

*/

struct Point {
    int x;
    int y;
};

void structs() {
    Point p1 = {1, 2};
    
    Point p2;
    p2.x = 3;
    p2.y = 4;

    Point *pp = &p2;
    pp->y = 5; // equivalent to "(*pp).y = 5;"
}

// 12. Pointers and structs

void setToZero(Point *p) {
    p->x = 0;
    p->y = 0;
}

// 13. Pointers and arrays

void printArray(int *arr, int size) {
    while (size > 0) {
        cout << *arr;
        arr = arr + 1;
        size = size - 1;
    }
    cout << endl;
}

void printArrayTest() {
    int arr[] = {8,6,7,5,3,0,9};
    printArray(arr, 7);
}

// 14. Arrays of structs

// const because we're not updating p
void printPoint(const Point &p) {
    cout << "(" << p.x << ", " << p.y << ")";
}

void printArrayOfPoints(Point arr[], int size) {
    for (int i = 0; i < size; i++) {
        printPoint(arr[i]);
        cout << endl;
    }
}

// 15. Dynamic Memory Allocation

void dynamic_memory_allocation() {
    int x = 5; // local vars and function parameters are defined 
               // on the stack

    // anything declared with new lives in the heap, and it's up 
    // to you to keep track of the memory
    int *y = new int; 
    *y = 7;

    // memory allocated using new is freed using delete
    delete y;
}

// 16. Linked-lists
struct Node {
    int data;
    Node *next;
};

struct LinkedList {
    Node *head;
    Node *tail;
};

// make the list 1->2->3
LinkedList* one_two_three() {
    LinkedList *l = new LinkedList;

    Node *one = new Node;
    Node *two = new Node;
    Node *three = new Node;
    one->data = 1;
    two->data = 2;
    three->data = 3;
    one->next = two;
    two->next = three;
    three->next = NULL;

    l->head = one;
    l->tail = three;

    return l;
}

// 17. Strings

#include <cstring>

void c_strings() {
    cout << "BEGIN C_STRINGS EXAMPLE" << endl;

    char s1[50] = "cat";
    const char *s2 = "dog";

    cout << "length of s1: " << strlen(s1) << endl;

    cout << "strcmp(s1, s2): " << strcmp(s1, s2) << endl;
    cout << "strcmp(s2, s1): " << strcmp(s2, s1) << endl;
    cout << "strcmp(s1, s1): " << strcmp(s1, s1) << endl;

    strcat(s1, s2);

    cout << "s1: " << s1 << endl;

    strcpy(s1, s2);

    cout << "s1: " << s1 << endl; 

    cout << "END C_STRINGS EXAMPLE" << endl;  
}

#include <string>

void cpp_strings() {
    cout << "BEGIN STRINGS EXAMPLE" << endl;

    string fruit = "Apple";

    int len = fruit.length();
    cout << "len: " << len << endl;

    int pos = fruit.find('l');
    cout << "pos: " << pos << endl;

    string part = fruit.substr(1,3);
    cout << "part: " << part << endl;

    fruit.erase(2,3);
    cout << "fruit after erase: " << fruit << endl; 

    fruit.insert(2,"ricot");
    cout << "fruit after insert: " << fruit << endl; 

    fruit.replace(2,5,"ple");
    cout << "fruit after replace: " << fruit << endl; 

    cout << "END STRINGS EXAMPLE" << endl;
}

// 18. Iteration through lists

void print_list_twice(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        cout << cur->data << endl;
        cur = cur -> next;
    }

    for (Node *cur = head; cur != NULL; cur = cur->next) {
        cout << cur->data << endl;
    }
}

// 19. Recursion, recursion on linked lists/strings

/* 

Recursion is when a function calls itself
base case, recursive case

In the recursive case, something must always get smaller!

think about what is happening on the stack

*/

// compute nᵖ -- this is a bit similar to the factorial function, 
// isn't it?
double pow(double n, int p) {
    if (p == 0) return 1.0;
    else return n * pow(n, p-1);
}

void free_linked_list_recursively(Node *head) {
    if (head == NULL) return;

    free_linked_list_recursively(head->next);
    delete head;
}

void free_linked_list_recursively2(Node *head) {
    if (head == NULL) return;

    Node *rest = head->next;
    delete head; // if you do it this way, make sure to save rest
    free_linked_list_recursively2(rest);
}

void print_list_backwards(Node *head) {
    if (head == NULL) return;

    print_list_backwards(head->next);
    cout << head->data << endl;
}

Node* deleteValueRecursively(Node *head, int value) {
    // base case: empty list, nothing to delete
    if (head == NULL) return NULL;

    // recursive case: list is not empty, split into head and rest
    Node *new_rest = deleteValueRecursively(head->next, value);
    // we get to assume new_rest is a list without any "data"s set to
    // "value"

    if (head->data == value) {
        delete head; // head should not appear in the final answer
        return new_rest;
    } else {
        // we need to keep head

        head->next = new_rest;

        return head;
    }
}

int main(int argc, char *argv[]) {
    int arr[] = {1,2,3};
    printArray(array_twice(arr, 3), 6);

    pointers();

    structs();

    Point p;
    setToZero(&p);

    printArrayTest();

    Point ps[] = {{0,1}, {1,2}, {2,3}};
    printArrayOfPoints(ps, 3);

    dynamic_memory_allocation();

    print_list_backwards(one_two_three()->head);

    c_strings();

    cpp_strings();

    cout << pow(2, 3) << endl;

    return 0;
}