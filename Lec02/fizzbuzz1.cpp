#include <iostream>
using namespace std;

int min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

void fizzbuzz1(int n) {
    if (n % 3 == 0) {
        cout << "fizz\n";
    } else {
        cout << n << endl;
    }
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    fizzbuzz1(n);  

    return 0;
}