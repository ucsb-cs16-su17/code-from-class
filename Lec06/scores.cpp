#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int scores[10]={20,10,50,20,10,50,20,10,50,100};
    double average = 0.0;
    for (int i = 0; i < 10; i++) {
        average += scores[i];
    }
    average = average / 10.0;

    cout << "Average: " << average << endl;

    return 0;
}

                                                   
