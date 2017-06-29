#include <iostream>
using namespace std;

// function declaration
void fizzbuzz(int n);

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        fizzbuzz(i);
    }

    return 0;
}

// function definition
void fizzbuzz(int n) {
    if (n % 3 == 0 && n % 5 == 0) {
        cout << "fizzbuzz\n";
    } else if (n % 3 == 0) {
        cout << "fizz\n";
    } else if (n % 5 == 0) {
        cout << "buzz\n";
    } else {
        cout << n << endl;
    }
}