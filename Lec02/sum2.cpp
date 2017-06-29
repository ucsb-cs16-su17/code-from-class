#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int n;

    cout << "Enter n\n";
    cin >> n;

    double sum = 0.0;

    for (int i = 1; i <= n; i = i + 1) {
        sum = sum + 1.0/i;
    }

    cout << "Sum of the first " << n 
         << " terms is: " << sum << endl;


    return 0;
}