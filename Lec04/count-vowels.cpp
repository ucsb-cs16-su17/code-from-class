#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream ifs;
    ifs.open("file.txt");

    if (ifs.fail()) {
        return 1;
    }

    int numberOfVowels = 0;
    while (1) {
        char c;
        ifs >> c;
        if (ifs.eof()) {
            break;
        }

        if (c == 'a' || c == 'e' || 
            c == 'i' || c == 'o' || 
            c == 'u' ||
            c == 'A' || c == 'E' || 
            c == 'I' || c == 'O' || 
            c == 'U') {
            numberOfVowels++;
        }
    }

    cout << numberOfVowels << endl;

    ifs.close();

    return 0;
}