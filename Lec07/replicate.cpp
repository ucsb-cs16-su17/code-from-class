#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

char translate(char c) {
    c = toupper(c);

    if (c == 'A') {
        return 'T';
    } else if (c == 'T') {
        return 'A';
    } else if (c == 'G') {
        return 'C';
    } else { // 
        return 'G';
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        cerr << "usage: " << argv[0] << " filename" << endl;
        exit(1);
    }

    ifstream ifs;
    ifs.open(argv[1]);

    if (ifs.fail()) {
        cerr << "bad filename\n";
        exit(1);
    }

    while (true) {
        if (ifs.eof()) {
            break;
        }

        char c;
        ifs >> c;
        cout << static_cast<char>(tolower(translate(c)));
    }

    cout << endl;

    return 0;
}