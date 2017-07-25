#include <iostream>
#include <string>
using namespace std;

struct Character {
    string name;
    int yearAtHogwarts;
    bool isBoyWhoLived;
    bool isCurrentlyPosessedByTomRiddlesDiary;
};

void endOfBook2(Character *c) {
    c->yearAtHogwarts += 1;
    if (c->isCurrentlyPosessedByTomRiddlesDiary)
        c->isCurrentlyPosessedByTomRiddlesDiary = false;
}

int main(int argc, char const *argv[])
{
    Character Harry;
    Harry.name = "Harry";
    Harry.yearAtHogwarts = 2;
    Harry.isBoyWhoLived = true;
    Harry.isCurrentlyPosessedByTomRiddlesDiary = false;

    Character Ginny = {"Ginny", 1, false, true};
    endOfBook2(&Ginny);

    cout << Ginny.isCurrentlyPosessedByTomRiddlesDiary << endl;

    return 0;
}