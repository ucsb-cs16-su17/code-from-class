#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream ifs;
    ifs.open(argv[1]);

    // ...

    int i;
    while (ifs >> i) {
        cout << i << endl;
    }

    // ...

    return 0;
}