#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int n;

    cout << "Enter width\n";
    cin >> n;

    for (int i = 1; i <= n; i = i + 1) {
        for (int j = 1; j <= n; j = j + 1) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}