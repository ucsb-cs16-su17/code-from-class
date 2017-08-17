#include <iostream>
using namespace std;

int binarySearchHelper(int arr[], int num, int low, int high);

// searches for num in arr, returning the index if found 
// and -1 if not found
// requires a helper function
int binarySearch(int arr[], int size, int num) {
    return binarySearchHelper(arr, num, 0, size-1);
}

int binarySearchHelper(int arr[], int num, int low, int high) {
    // the high and low indices no longer make sense
    if (high < low) return -1;
    else {
        // look in the middle of high and low
        int i = (high + low) / 2;
        // the number we were looking for was bigger than arr[i],
        // so look from [i+1, high]
        if (arr[i] < num) return binarySearchHelper(arr, num, i+1, high);
        // the number we were looking for was smaller than arr[i],
        // so look from [low, i-1]
        else if (arr[i] > num) return binarySearchHelper(arr, num, low, i-1);
        // we found the number, return its index
        else return i;
    }
}

int binarySearchIterative(int arr[], int size, int num) {
    int low = 0, high = size-1;
    while (low <= high) {
        int i = (high + low) / 2;
        if (arr[i] < num) low = i+1;
        else if (arr[i] > num) high = i-1;
        else return i;
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    // 0 - 9
    int arr[10] = {12, 15, 27, 32, 42, 44, 67, 88, 91, 103};
    cout << binarySearch(arr, 10, 67) << endl;
    cout << binarySearchIterative(arr, 10, 67) << endl;

    return 0;
}