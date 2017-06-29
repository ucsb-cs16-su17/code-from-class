#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter the limits of the sequence\n";
    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        cout << i;
        if (i < n) {
            cout << ", ";
        }
    }

    cout << endl;

    return 0;
}