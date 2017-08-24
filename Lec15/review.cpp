#include <iostream>
using namespace std;

// 1. Flow control if-else statements

void if_else() {
    int x = 5;
    int y = 17;

    if (x > 4 && y < 7) {
        cout << "A" << endl;
    } else if (x < 4 && y > 12) {
        cout << "B" << endl;
    } else {
        cout << "C" << endl;
    }

    // order of null checks matter
    /*
    int *p = NULL;
    if (p != NULL && *p < 5) {

    }

    if (*p < 5 && p != NULL) {
        
    }
    */
}

// 2. Data types and declarations

void data_types_and_decls() {
    int x;
    bool b;
    char c;
    int *y = &x;

    // type_name var_name (optionally: = value)

    bool b2 = 0;
    bool b3 = 23412453145;
}

// 3. While loops

void while_loops() {
    int x = 0;

    while (x < 0) {
        cout << "this never happens" << endl;
    }

    do {
        cout << "but this does" << endl;
    } while (x < 0);
}

// 4. For loops

void for_loops() {
    // for loop order:
    // 1. initialize stuff (int i = 10)
    // 2. check termination condition (i >= 1)
    // 3. execute body
    // 4. update (i--)
    // go to 2

    for (int i = 10; i >= 1; i--) {
        cout << i << endl;
    }
    cout << "lift off!" << endl;

    // equivalent to
    /*
    int i = 10;
    while (i >= 1) {
        cout << i << endl;
        i--;
    }
    cout << "lift off!" << endl;
    */
}

// 5. Evaluating expressions

/*
    
see prececedence table in the book

*/

void exprs() {
    int x = 5, y = 7;
    bool b1 = true, b2 = false;

    // how do write the parentheses?
    cout << (x + 1 < 5 && y == 9 || b1 && b2) << endl;
}

// 6. Data representation

/*

ints/pointers: 4 bytes
doubles: 8 bytes
chars: 1 byte
see book for more details

0x87 (87 in base 16) is what in decimal? 135
87 (in base 10) is what in hex? 57
                        in binary? 01010111

*/

// 7. Arrays

void arrays() {
    int arr[] = {1, 2, 3}; // can initialize with data immediately

    int arr2[3]; // or wait
    arr2[0] = 4;
    arr2[1] = 5;
    arr2[2] = 6;

    for (int i = 0; i < 3; i++) {
        cout << arr[i];
        // 2 = length (= 3) - 1
        if (i < 2) cout << ", ";
    }
    cout << endl;
}

// 8. Passing parameters to functions 
//    (by value, by pointer, by reference)

void by_value(int x) {
    x = 5;
}

void by_pointer(int *x) {
    *x = 6;
}

void by_reference(int &x) {
    x = 7;
}

void test_parameter_passing() {
    int y = 4;
    by_value(y);
    cout << y << endl; // does nothing
    by_pointer(&y);
    cout << y << endl; // changes
    by_reference(y);
    cout << y << endl; // changes
}

// 9. Passing arrays to functions and returning arrays 
//    from functions

// 10. Pointers

// 11. Structs

// 12. Pointers and structs

// 13. Pointers and arrays

// 14. Arrays of structs

// 15. Dynamic Memory Allocation

// 16. Linked-lists

// 17. Strings

// 18. Iteration through lists

// 19. Recursion, recursion on linked lists/strings

int main(int argc, char *argv[]) {
    if_else();
    while_loops();
    for_loops();
    exprs();
    arrays();
    test_parameter_passing();

    return 0;
}