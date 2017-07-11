#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char** argv )
{
  ifstream theFile;
  string thisLine;
  theFile.open( argv[1] );
  while ( 1 ) {
    getline(theFile, thisLine);
    if (theFile.eof()) break;
    cout << thisLine << endl; 
  }
  theFile.close();
}
