#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int d = 5;
  int & e = d;
  int f = 10;
  e = f;

  d--;
  f++;

  cout << d << " " << e << " " << f << endl;

  return 0;
}