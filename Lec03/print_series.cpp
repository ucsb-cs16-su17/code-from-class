#include <iostream>
#include <cstdlib>
using namespace std;

void printSeries(int low, int high);

int main(int argc, char *argv[])
{
    if (argc == 3) {
        int low = atoi(argv[1]);
        int high = atoi(argv[2]);
        printSeries(low, high);
    } else {
        cerr << "usage: " << argv[0] << " low high\n";
        exit(1);
    }

    return 0;
}

void printSeries(int low, int high) {
    int i = low;
    while (i <= high) {
        cout << i;
        if (i < high) {
            cout << ", ";
        }
        i++;
    }
    cout << endl;
}