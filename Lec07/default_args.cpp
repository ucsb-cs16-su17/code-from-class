#include <iostream>
using namespace std;

int add1(int x = 0) {
    return x+1;
}

int main(int argc, char const *argv[])
{
    cout << add1(5) << endl;
    cout << add1() << endl; // equivalent to  add1(0);
    return 0;
}