#include <iostream>
#include <string>
using namespace std;

// string library functions:
// http://www.cplusplus.com/reference/string/string/

int main(int argc, char const *argv[])
{
    string fruit = "Apple";

    int len = fruit.length();
    cout << "len: " << len << endl;

    int pos = fruit.find('l');
    cout << "pos: " << pos << endl;

    string part = fruit.substr(1,3);
    cout << "part: " << part << endl;

    fruit.erase(2,3);
    cout << "fruit after erase: " << fruit << endl; 

    fruit.insert(2,"ricot");
    cout << "fruit after insert: " << fruit << endl; 

    fruit.replace(2,5,"ple");
    cout << "fruit after replace: " << fruit << endl; 

    return 0;
}