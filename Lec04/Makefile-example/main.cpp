#include <iostream>
#include "isPositive.h"
#include "isNegative.h"
using namespace std;

int main(int argc, char *argv[])
{
    int m;
    cin >> m;

    cout << isPositive(m) << endl;
    cout << isNegative(m) << endl;
    return 0;
}