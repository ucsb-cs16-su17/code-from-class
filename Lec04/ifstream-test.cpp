#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream ifs;
    ifs.open("file.txt");

    if (ifs.fail()) {
        return 1;
    }

    string thisLine;
    getline(ifs,thisLine);
    cout<< thisLine << " "; 
    getline(ifs,thisLine);
    cout<< thisLine;

    ifs.close();

    return 0;
}