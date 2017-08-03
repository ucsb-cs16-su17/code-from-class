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

LinkedList* arrayToLinkedList(int a[], int size);
void printList(LinkedList *ll);
void printList2(LinkedList *ll);

int lengthOfList(LinkedList *list) {
    int counter = 0;

    Node *curr = list->head; // (*list).head
    while (curr != NULL) {
        counter++;
        curr = curr->next;
    }

    return counter;
}

void freeLinkedList(LinkedList *list) {
    if (list == NULL) return;

    Node *curr = list->head;
    if (curr == NULL) {
        // list was an empty list
        delete list;
    } else {
        // list had stuff inside
        while (curr->next != NULL) {
            Node *next = curr->next; // curr isn't null right now
            delete curr;
            curr = next;
        }
        // curr now points to the last element of the list
        delete curr;
        delete list;
    }
}

void freeLinkedList2(LinkedList *list) {
    if (list == NULL) return;

    Node *curr = list->head;
    if (curr != NULL) {
        // list had stuff inside
        while (curr->next != NULL) {
            Node *next = curr->next; // curr isn't null right now
            delete curr;
            curr = next;
        }
        // curr now points to the last element of the list
        delete curr;
    }

    delete list;
}


int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4};
    LinkedList *ll = arrayToLinkedList(a, 4);
    printList(ll);
    printList2(ll);

    freeLinkedList(ll);

    return 0;
}

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

