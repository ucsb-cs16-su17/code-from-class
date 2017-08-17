#include <iostream>
using namespace std;

struct Expression {
    char operation; // '+', '*', or 'N' for number

    // if operation == 'N', this represents the number
    int *num;

    // if operation is '+' or '*', we give the left and right sides here
    Expression *lhs; 
    Expression *rhs;
};

int evaluate(Expression e) {

}

int main(int argc, char const *argv[]) {
    int five = 5, three = 3, two = 2;
    Expression five = {'N', &five, NULL, NULL};
    Expression three = {'N', &three, NULL, NULL};
    Expression two = {'N', &two, NULL, NULL};

    Expression fivePlusThree = {'+', NULL, &five, &three}; // 5 + 3
    Expression fivePlusThreeTimesTwo = 
        {'*', NULL, &fivePlusThree, &two}; // (5 + 3) * 2

    cout << evaluate(fivePlusThreeTimesTwo) << endl;

    return 0;
}