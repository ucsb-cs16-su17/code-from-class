#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main(int argc, char *argv[])
{
    int base, number;

    cout << "enter base: ";
    cin >> base;
    assert(base <= 16 && base >= 2);
    cout << "enter number: ";
    cin >> number;

    string output = "";
    if (number == 0) {
        output = "0";
    } else {
        while (number != 0) {
            int lastDigit = number % base;
            char digit;
            if (lastDigit <= 9) {
                // http://en.cppreference.com/w/cpp/language/ascii
                digit = '0' + static_cast<char>(lastDigit);
            } else {
                digit = 'A' + static_cast<char>(lastDigit - 10);
            }
            output = digit + output;
            number = number / base;
        }
    }

    cout << output << endl;

    return 0;
}