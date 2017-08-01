#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

// void printPoint(Point &p) {
// void printPoint(Point *p) {
void printPoint(Point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

void initializeAllPointsToOrigin(Point ps[], int size) {
    for (int i = 0; i < size; i++) {
        ps[i].x = 0;
        ps[i].y = 0;
    }
}

int globalVariable = 0;

int main(int argc, char *argv[])
{
    Point arr[10]; // declare an array of 10 points

    for (int i = 0; i < 10; i++) {
        printPoint(arr[i]);
    }

    initializeAllPointsToOrigin(arr, 10);

    cout << "now everything should be (0, 0)\n";

    for (int i = 0; i < 10; i++) {
        printPoint(arr[i]);
    }

    return 0;
}