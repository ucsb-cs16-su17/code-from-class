#include <iostream>
using namespace std;

// function declaration
void fizzbuzz2(int n);

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    fizzbuzz2(n);  

    return 0;
}

// function definition
void fizzbuzz2(int n) {
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