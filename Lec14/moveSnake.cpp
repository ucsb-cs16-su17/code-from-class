// usage: ./moveSnake file.txt size

#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cassert>
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

struct Node {
    Point data; // Point instead of int
    Node *next;
};















/***********************************/
/* Recursive Function Declarations */
/***********************************/

// creates a snake of a given size, with all points of the snake
// starting out "curled up" at a single starting point
Node* makeSnakeRecursively(int size, Point startingPoint);

void drawSnakeRecursively(Node *n);

void deleteLastNodeRecursively(Node *n);



















void drawSnakeRecursively(Node *n) {
    if (n == NULL) {
        return; // write out an "empty" snake, so do nothing
    } else {
        // draw the head
        writeCharAtCoordinate(n->data.y, n->data.x, '*');
        // draw the rest (the list is getting smaller)
        drawSnakeRecursively(n->next);
    }
}

void deleteLastNodeRecursively(Node *n) {
    // is n the second to last node?
    if (n != NULL && n->next != NULL && n->next->next == NULL) {
        delete n->next;
        n->next = NULL;
    } else if (n != NULL) {
        // n wasn't the second to last node; move closer to the end of the list
        deleteLastNodeRecursively(n->next);
    }
}

// returns the head of the new, moved list
Node* moveSnake(Node *head, Point direction) {
    // make a new head
    Node *newHead = new Node;
    // the new head takes the old head's position, offset by the current direction
    newHead->data.x = head->data.x + direction.x;
    newHead->data.y = head->data.y + direction.y;

    // go through the walls
    if (newHead->data.x > cols) newHead->data.x = 1;
    else if (newHead->data.x <= 0) newHead->data.x = cols;
    if (newHead->data.y > rows) newHead->data.y = 1;
    else if (newHead->data.y <= 0) newHead->data.y = rows;

    // new head becomes the head
    newHead->next = head;

    // remove the old end of the snake
    deleteLastNodeRecursively(newHead);

    // return the updated list
    return newHead;
}

// creates a snake of a given size, with all points of the snake
// starting out "curled up" at a single starting point
Node* makeSnakeRecursively(int size, Point startingPoint) {
    if (size == 0) return NULL;

    Node *head = new Node;
    head->data = startingPoint;
    head->next = makeSnakeRecursively(size-1, startingPoint);

    return head;
}

// read the file to see if we should change direction
void possiblyUpdateDirection(Point &direction, char *fileName) {
    fstream fs;
    fs.open(fileName);

    if (!fs.fail()) {
        // try to read a character 
        char c;
        if (fs >> c) {
            // we successfully read a character
            // figure out direction
            if (c == 'u') // up
                direction.x = 0, direction.y = -1;
            else if (c == 'd') // down
                direction.x = 0, direction.y = 1;
            else if (c == 'l') // left
                direction.x = -1, direction.y = 0;
            else // right
                direction.x = 1, direction.y = 0;

            // clear out the file, indicating that we read the direction
            fs.seekp(0); // go to the start of the file
            fs << " ";   // write a space to overwrite the old direction
        }
    }

    fs.close();
}

int main(int argc, char** argv)
{
    assert(argc == 3);
    srand(time(0)); // start off the random number generator 
                    // by giving it the current time
    clearScreen();

    const double refreshRate = 0.15;
    const int sizeOfSnake = atoi(argv[2]);
    assert(sizeOfSnake >= 1);

    int randomInitialX = rand() % cols + 1; // picks a number in [1, cols]
    int randomInitialY = rand() % rows + 1;

    Point p = {randomInitialX, randomInitialY};
    
    Point direction = {0,0}; // snake starts out not moving
    // snake is a list of Nodes with length = sizeOfSnake,
    // and all points start out at p
    Node *snake = makeSnakeRecursively(sizeOfSnake, p);
    
    while (true) {
        clearScreen();
        drawSnakeRecursively(snake);
        wait(refreshRate);

        // check the control file to see if we should change our current direction
        possiblyUpdateDirection(direction, argv[1]);

        // move the snake using the possibly new direction
        snake = moveSnake(snake, direction);
    }

    clearScreen();
    cout << endl;
    return 0;
}






///////////////////////////////////////////////
// Extra stuff you don't need to worry about //
///////////////////////////////////////////////

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