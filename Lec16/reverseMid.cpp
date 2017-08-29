// Midterm 2, Problem 4

#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void reverseMid(int arr[], int size) {
    for (int i = 1; i < size / 2; i++) {
        swap(arr[i], arr[size-1-i]);
    }
}

void reverseMid2(int arr[], int size) {
    int left = 1;
    int right = size-2;

    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main(int argc, char const *argv[])
{

    int arr1[] = {10};
    reverseMid(arr1, 1);
    printArray(arr1, 1);

    int arr2[] = {10, 20};
    reverseMid(arr2, 2);
    printArray(arr2, 2);

    int arr3[] = {10, 20, 30};
    reverseMid(arr3, 3);
    printArray(arr3, 3);

    int arr4[] = {10, 20, 30, 40};
    reverseMid(arr4, 4);
    printArray(arr4, 4);

    int arr5[] = {10, 20, 30, 40, 50};
    reverseMid(arr5, 5);
    printArray(arr5, 5);

    int arr6[] = {10, 20, 30, 40, 50, 60};
    reverseMid(arr6, 6);
    printArray(arr6, 6);
    
    return 0;
}