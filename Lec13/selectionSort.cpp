#include <iostream>
using namespace std;

/* ints */

// index of the minimum value in the array,
// only looking from arr[low] to arr[high]
int indexOfMin(int arr[], int low, int high) {
    int min = arr[low];
    int minIndex = low;
    for (int i = low+1; i <= high; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = indexOfMin(arr, i, size-1);
        swap(arr[i], arr[minIndex]);
    }
}

/* chars */

void swap(char &x, char &y) {
    char temp = x;
    x = y;
    y = temp;
}

int indexOfMin(char arr[], int low, int high) {
    char min = arr[low];
    int minIndex = low;
    for (int i = low+1; i <= high; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void selectionSort(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = indexOfMin(arr, i, size-1);
        swap(arr[i], arr[minIndex]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[15] = {23,42,2145342,32,234,434,2134,154,354,3452125,467,5656,56,45354,1};
    selectionSort(arr, 15);

    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    char s[10] = {'q','w','e','r','t','y','u','i','o','p'};
    selectionSort(s, 10);

    for (int i = 0; i < 10; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    // similarly, YOU CAN TOTALLY SORT STRINGS (which are just arrays of characters deep down)

    return 0;
}