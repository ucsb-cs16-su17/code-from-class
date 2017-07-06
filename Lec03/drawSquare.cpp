#include "drawSquare.h"

string drawSquare(int width) {
    string s = "";

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            s = s + "*";
        }
        s += "\n";
    }
    s = s + "\n";

    return s;
}