#include <iostream>
using namespace std;

double abs(double x) {
    if (x < 0.0) return -x;
    else return x;
}

bool approxEqual(double x, double y) {
    return (abs(x - y) < 0.000001);
}

double sqrt(double x) {
    double low = 0;
    double high = x;
    double guess = x;

    while (!approxEqual(guess*guess, x)) {
        // my mistake was having "double guess = ..."
        // instead of just "guess = ..."
        guess = (high + low) / 2.0;

        if (guess*guess > x) {
            // guess was too high; guess between low and guess
            high = guess;
        } else {
            // guess was too low; guess between guess and high
            low = guess;
        }
    }

    return guess;
}

int main(int argc, char const *argv[])
{
    cout << sqrt(9.0) << endl;
    return 0;
}