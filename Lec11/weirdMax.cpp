#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

int maxWithPointers1(int *x, int *y) {
  *x = INT_MAX;
  if (*x > *y)
    return *x;
  else
    return *y;
}

int maxWithPointers2(const int *x, const int *y) {
  // *x = INT_MAX; // are we allowed to do this now?
  if (*x > *y)
    return *x;
  else
    return *y;
}

int main(int argc, char *argv[])
{
    // argv[0] = "Am I allowed to do this?";

    int x = 5, y = 7;
    cout << "max1: " << maxWithPointers1(&x, &y) << endl;
    cout << "x: " << x << " y:" << y << endl;

    x = 5;
    y = 7;
    cout << "max2: " << maxWithPointers2(&x, &y) << endl;
    cout << "x: " << x << " y:" << y << endl;

    return 0;
}
