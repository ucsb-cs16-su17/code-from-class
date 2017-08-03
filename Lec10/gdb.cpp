/*

compile with: g++ -g gdb.cpp

$> gdb a.out 
...
(gdb) run
Starting program: /cs/student/lawtonnichols/a.out

Program received signal SIGSEGV, Segmentation fault.
0x0000000000400861 in main (argc=1, argv=0x7fffffffdf98) at asdf.cpp:8
8       cout << *x << endl;
(gdb) bt
#0  0x0000000000400861 in main (argc=1, argv=0x7fffffffdf98) at asdf.cpp:8
(gdb) print x
$1 = (int *) 0x0
(gdb) backtrace
#0  0x0000000000400861 in main (argc=1, argv=0x7fffffffdf98)
    at asdf.cpp:8

(Ctrl-D to quit gdb)

*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int *x = NULL;

    cout << *x << endl;

    return 0;
}