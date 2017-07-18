#include <iostream>
using namespace std;

int HarryPotter = 0;

// non-array function parameters are also locals 
// that do not affect their original values
void GobletOfFire() {
  int CedricDiggory = 4;
  HarryPotter = 4;

  cout << HarryPotter << endl;
  cout << CedricDiggory << endl;
}

int main() {
  cout << HarryPotter << endl;
  GobletOfFire();
  cout << HarryPotter << endl;
  HarryPotter = 7;
  cout << HarryPotter << endl;

  return 0;
}
