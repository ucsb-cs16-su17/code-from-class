

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int *p, x=10;
    p = &x;
    *p = *p + 1;

    cout << *p << endl;
    cout << x << endl;

    return 0;
}
