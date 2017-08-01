#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head;
};

LinkedList* arrayToLinkedList(int a[], int size) {
    // make an empty linked list
    LinkedList *ll = new LinkedList;
    ll->head = NULL;

    // iterate through a and add one more element each time
    for (int i = 0; i < size; i++) {

        if (ll->head == NULL) {
            // make the first element of the list
            ll->head = new Node;
            ll->head->data = a[i];
            ll->head->next = NULL;
        } else {
            // make elements after the first
            Node *n = new Node;
            n->data = a[i];
            n->next = NULL;

            // figure out where to insert the new node
            Node *curr = ll->head; // start at the first element of the list
            while (curr->next != NULL) {
                curr = curr->next;
            }
            // curr->next is definitely NULL now
            curr->next = n;
        }

    }

    return ll;
}

void printList(LinkedList *ll) {
    Node *curr = ll->head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void printList2(LinkedList *ll) {
    for (Node *curr = ll->head; curr != NULL; curr = curr->next) {
        cout << curr->data << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4};
    LinkedList *ll = arrayToLinkedList(a, 4);
    printList(ll);
    printList2(ll);

    return 0;
}

