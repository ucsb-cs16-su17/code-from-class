#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    ofstream ofs;
    ofs.open("output.txt");
    if (ofs.fail()) {
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        ofs << i << endl;
    }

    ofs.close();

    return 0;
}