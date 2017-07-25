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

const int rows = terminalRows();
const int cols = terminalCols();

struct Point {
    int x;
    int y;
};

int main(int argc, char** argv)
{
    srand(time(0));
    clearScreen();

    int randomInitialX = rand() % cols + 1;
    int randomInitialY = rand() % rows + 1;

    Point p = {randomInitialX, randomInitialY};
    
    writeCharAtCoordinate(p.y, p.x, '*');
    wait(0.5);
    

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