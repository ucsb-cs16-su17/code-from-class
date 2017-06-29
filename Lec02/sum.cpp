#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int n;

    cout << "Enter n\n";
    cin >> n;

    int sum = 0;

    assert(n >= 1);
    for (int i = 1; i <= n; i = i + 1) {
        sum = sum + i;
    }

    cout << "Sum of the first " << n 
         << " terms is: " << sum << endl;

    cout << 0.1 << endl;

    return 0;
}