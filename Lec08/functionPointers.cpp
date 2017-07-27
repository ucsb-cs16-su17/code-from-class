#include <iostream>
using namespace std;

int plus1(int x) {
    return x + 1;
}

int minus1(int x) {
    return x - 1;
}

int main(int argc, char const *argv[])
{
    int (*fp)(int);

    fp = &plus1;
    cout << (*fp)(5) << endl;
    cout << fp(5) << endl; // alternative, simpler syntax

    fp = &minus1;
    cout << (*fp)(5) << endl;

    return 0;
}
