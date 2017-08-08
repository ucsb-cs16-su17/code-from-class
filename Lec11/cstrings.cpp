#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char *argv[])
{
    char s1[50] = "cat";
    const char *s2 = "dog";

    cout << "length of s1: " << strlen(s1) << endl;

    cout << "strcmp(s1, s2): " << strcmp(s1, s2) << endl;
    cout << "strcmp(s2, s1): " << strcmp(s2, s1) << endl;
    cout << "strcmp(s1, s1): " << strcmp(s1, s1) << endl;

    strcat(s1, s2);

    cout << "s1: " << s1 << endl;

    strcpy(s1, s2);

    cout << "s1: " << s1 << endl;    

    return 0;
}