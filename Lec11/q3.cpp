#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
    char s1[4] = "abc", s2[4] = "EFG"; 
    if (strcmp(s1, s2)) cout << "Hi!"; 
    else cout << "Hey!";

    cout << endl << "------" << endl;

    string s3 = "Mark";
    string s4 = "Jill";
    for (int i = 0; i <= s3.length(); i++)
        s4[i] = s3[i];
    if (s3 == s4) s3 = "Art";
    cout << s3 << " " << s4 << endl;

    return 0;
}
