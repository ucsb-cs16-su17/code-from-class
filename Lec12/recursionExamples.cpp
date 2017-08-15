#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void printBackwards(Node *head) {
    if (head == NULL) return;

    printBackwards(head->next);
    cout << head->data << endl;
}

int sum(Node *head) {
    if (head == NULL) return 0;

    return head->data + sum(head->next);
}

void printElementsBackwards(char *arr, int len) {
    if (len <= 0) {
        cout << endl;
        return;
    }

    char x = arr[len-1];
    cout << x;
    printElementsBackwards(arr, len-1);
}

// returns n!
int factorial(int n) {
    if (n <= 0) return 1;
    else return n*factorial(n-1);
}

// precondition: n always >= 1
// sum the numbers from 1 to n
int sum(int n) {
    if (n == 1) return 1;
    else return sum(n-1) + n;
}

// returns the nth fibonacci number 
// (there's a lot of wasted work here, sadly)
int fibonacci(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-2) + fibonacci(n-1);
}

// searches for num in arr, returning the index if found 
// and -1 if not found
// requires a helper function
int binarySearch(int arr[], int size, int num);
int binarySearchHelper(int arr[], int num, int low, int high); 

int main(int argc, char const *argv[])
{
    Node *list = new Node;
    list->data = 1;
    list->next = new Node;
    list->next->data = 2;
    list->next->next = new Node;
    list->next->next->data = 3;
    list->next->next->next = NULL;
    // list is now [1,2,3]

    printBackwards(list);

    cout << sum(list) << endl;

    char arr[] = "Bond007";
    printElementsBackwards(arr, 7);

    cout << factorial(5) << endl;

    cout << sum(5) << endl;

    cout << fibonacci(7) << endl;

    // int arr[10] = {12, 15, 27, 32, 42, 44, 67, 88, 91, 103};
    // cout << binarySearch(arr, 10) << endl;

    return 0;
}