//declare preprocessor directives 
#include <iostream>
#include <fstream>
#include <string>
#include "Statistics.h"
//namespace std for easy coding
using namespace std;

int main(){
  //declare input file objeect 
  ifstream myFile;
  //declare variables 
  string fileName;
  int size;
  int userChoice;
  //ask user for file name; repeat if file name is invalid
  do{
    cout << "Please enter the name of your data file: ";
    cin >> fileName;
    myFile.open(fileName.c_str());
    if(!myFile){
      cout << "Invalid file name. Try again.\n";
    }
  }while(!myFile);
  //create an array based on the size specified in text file
  myFile >> size;
  float myNums[size];
  //fill the created array with the numbers from the supplied text file 
  for(int i = 0; i < size; i++){
    myFile >> myNums[i];
  }
  //sorts the provided numbers 
  quickSort(myNums, 0, size);  
  //ask user for input; repeat if input is invalid; and then run proper function based on user choice 
  do {
    do {
      cout << "Welcome to the Statistics Program!\n";
      cout << "1. See the Mean of the provided data set\n";
      cout << "2. See the Mode of the provided data set\n";
      cout << "3. See the Median of the provided data set\n";
      cout << "4. Quit\n";
      cout << "Enter your selection: ";
      cin >> userChoice;
      cout << endl;
	  if(userChoice <= 0 || userChoice > 4){
		  cout << "Not a valid selection. Please try again.\n";
		  cout << endl;
	  }
    } while(userChoice <= 0 || userChoice > 4);
	//runs statistics function based on user input
    if(userChoice == 1){
      cout << "The mean value of this data is " << findMean(myNums, size) << endl;
    }else if(userChoice == 2){
      cout << "The mode value of this data is " << findMode(myNums, size) << endl;
    }else if(userChoice == 3){
      cout << "The median value of this data is " << findMedian(myNums, size) << endl;
    }
    cout << endl;
	//ends when user inputs 4
  } while(userChoice < 4);

}
