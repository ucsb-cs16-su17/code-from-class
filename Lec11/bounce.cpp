#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int terminalRows();
int terminalCols();
void clearScreen();
void writeCharAtCoordinate(int row, int col, char c);
void wait(double seconds);

const int rows = terminalRows(); // how tall the terminal is
const int cols = terminalCols(); // how wide the terminal is

struct Point {
    int x;
    int y;
};

int main(int argc, char** argv)
{
    srand(time(0)); // start off the random number generator 
                    // by giving it the current time
    clearScreen();

    const double refreshRate = 0.05;

    int randomInitialX = rand() % cols + 1; // picks a number in [1, cols]
    int randomInitialY = rand() % rows + 1;

    Point p = {randomInitialX, randomInitialY};

    // pick direction (always different from <0,0>)
    int directionX;
    int directionY;
    do {
        directionX = rand() % 3 - 1; 
        directionY = rand() % 3 - 1;
    } while (directionX == 0 && directionY == 0);
    
    Point direction;
    direction.x = directionX;
    direction.y = directionY;
    
    while (true) {
        clearScreen();
        writeCharAtCoordinate(p.y, p.x, '*');
        wait(refreshRate);

        p.x += direction.x;
        p.y += direction.y;

        if (p.y == 1 || p.y == rows) {
            direction.y = -direction.y;
        }

        if (p.x == 1 || p.x == cols) {
            direction.x = -direction.x;
        }
    }

    clearScreen();
    cout << endl;
    return 0;
}






void wait(double seconds) {
    usleep(static_cast<unsigned int>(seconds * 1000000.0));
}

int terminalRows() {
    struct winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    return size.ws_row;
}

int terminalCols() {
    struct winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    return size.ws_col;
}

//https://en.wikipedia.org/wiki/ANSI_escape_code
const string CSI = "\33[";

void clearScreen() {
    cout << CSI << "2J" << flush;
}

void moveCursor(int row, int col) {
    cout << CSI << row << ";" << col << "H" << flush;
}

void writeCharAtCoordinate(int row, int col, char c) {
    moveCursor(row, col);
    cout << c << flush;
    moveCursor(rows, cols);
}

void hideCursor() {
    cout << CSI << "?25l" << flush;
}

void showCursor() {
    cout << CSI << "?25h" << flush;
}