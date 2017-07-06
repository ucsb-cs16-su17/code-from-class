#include <iostream>
#include <cstdlib>
using namespace std;

void drawTriangle(int base);

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "Enter the length of the base\n";
        int base;
        cin >> base;
        drawTriangle(base);
    } else if (argc == 2) {
        int base = atoi(argv[1]);
        drawTriangle(base);
    } else {
        cout << "You gave too many args.\n";
    }

    return 0;
}

void drawTriangle(int base) {
    cout << "pretend you see a triangle of base " 
         << base << endl;
}