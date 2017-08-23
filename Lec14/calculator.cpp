#include <iostream>
using namespace std;

struct Expression {
    char operation; // '+', '*', or 'N' for number

    // if operation == 'N', this represents the number
    int *num;

    // if operation is '+' or '*', we give the 
    // left and right sides here
    Expression *lhs; 
    Expression *rhs;
};

int evaluate(Expression e) {
    if (e.operation == 'N') {
        cout << "evaluate a number" << endl;
        return *(e.num);
    } else {
        // ask the smaller expressions for their results
        cout << "evaluate a " << e.operation << endl;
        int left_result = evaluate(*(e.lhs));
        int right_result = evaluate(*(e.rhs));
        if (e.operation == '+') {
            return left_result + right_result;
        } else {
            // operation was '*'
            return left_result * right_result;
        }
    }
}

int main(int argc, char const *argv[]) {
    int five_int = 5, three_int = 3, two_int = 2;
    Expression five = {'N', &five_int, NULL, NULL};
    Expression three = {'N', &three_int, NULL, NULL};
    Expression two = {'N', &two_int, NULL, NULL};

    Expression fivePlusThree = {'+', NULL, &five, &three}; // 5 + 3
    Expression fivePlusThreeTimesTwo = 
        {'*', NULL, &fivePlusThree, &two}; // (5 + 3) * 2

    cout << evaluate(fivePlusThreeTimesTwo) << endl;

    return 0;
}