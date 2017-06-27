/* 
multi-
line
comment
*/

// single-line comment

#include <iostream> // for cin/cout
#include <string>
using namespace std; // so we don't have to say std::cout/std::cin/std::endl everywhere

int main(int argc, char *argv[]) { // if you want access to command line arguments
    int myVariable = 1;
    myVariable = myVariable == 0;
    cout << myVariable << endl;

    bool b = true;
    char c = 'c';
    double d = 1.5;
    string s = "asdf";

    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << s << endl;

    cout << "What is your name?\n";
    cin >> s;
    cout << "Hello, " << s << "\n";

    cout << 5 / 0 << endl;

    cout << argv[0] << endl;

    cout << "argc: " << argc << endl;
    if (argc > 1) {
        cout << argv[1] << endl;
    }

    return 0;
}