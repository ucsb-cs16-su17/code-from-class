#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter the limits of the sequence\n";
    cin >> m >> n;

    int i = m;
    while (i <= n) {
        cout << i;
        if (i < n) {
            cout << ", ";
        }
        i++;
    }

    cout << endl;

    return 0;
}