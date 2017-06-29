#include <iostream>
#include <cassert> // http://www.cplusplus.com/reference/cassert/assert/
using namespace std;

int min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

void test_min() {
    assert(min(0, 1) == 0);
    assert(min(1, 0) == 0);
    assert(min(5, 5) == 5);
}

int main()
{
    test_min();
    return 0;
}