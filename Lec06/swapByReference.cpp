#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char const *argv[])
{
    int x = 5, y = 7;
    swap(x, y);
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    return 0;
}