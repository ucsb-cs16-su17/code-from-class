#include <iostream>
using namespace std;

// pre: x and y are not null
// post: x and y's values have been swapped
void swapValue(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int a=30, b=40;
    int *c = NULL;
    // swapValue(&a + 1, &b); // swap one past a
    // swapValue(&a + 10000, &b); 
    if (c != NULL)
        swapValue(c, &a); // swap wherever c is pointing and a
    // swapValue(0, &b); // swap NULL and b?
    cout << a << " " << b << endl;
}
