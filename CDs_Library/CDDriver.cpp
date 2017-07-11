#include <iostream>
#include <fstream>
#include "CDs.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "Error! Please reformat your command line."<<endl;
    cout << "Proper format: <Main.exe> <cds.txt>" << endl;
    return 1;
   }

  string userInput;
  CDs* foundCDs = new CDs;
  CDs* myCDs = new CDs;
  myCDs = createCDs(argv[1]);

  do{
    cout << "Enter an artist to obtain their CDs in the collection('q' to exit): ";
    getline(cin,userInput);

    foundCDs = findCDs(myCDs, userInput);

    if(userInput == "q"){
      cout << endl;
      cout << "Have a nice day!" << endl;
      break;
    }
    else if(foundCDs->___currentSize == 0){
      cout << endl;
      cout << "No CD's by that artist were found.";
    }else{
      cout << endl;
      displayCDs(foundCDs);
    }

  }while(userInput != "q");


}
