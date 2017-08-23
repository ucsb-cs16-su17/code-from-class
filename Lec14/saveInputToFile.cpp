// usage: ./saveInputToFile file.txt

#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void wait(double seconds);

// writes a single character c to fileName
// if successful, returns true
bool tryToWriteToFile(char *fileName, char c) {
    ofstream ofs;
    ofs.open(fileName);

    if (ofs.fail()) {
        ofs.close();
        return false;
    }

    ofs << c;
    ofs.close();
    return true;
}

int main(int argc, char** argv)
{
    while (true) {
        // read a character to write to the file
        char c;
        cin >> c;

        // try to write that character
        bool res = tryToWriteToFile(argv[1], c);

        // keep trying if we couldn't write the first time
        while (res == false) {
            cout << "failed" << endl;
            wait(1.0);
            res = tryToWriteToFile(argv[1], c);
        }
    }

    return 0;
}

//////////////////////////////////////////

void wait(double seconds) {
    usleep(static_cast<unsigned int>(seconds * 1000000.0));
}