/*
  Holden Ayers
  Lab 2 - AdvancedRoshambo
  03.02.2017
*/

//import the required C++ library, and the required header file
#include <iostream>
#include "Random.h"
#include <fstream>

//use namespace standard so you don't have to keep typing "std"
using namespace std;

//function to determine winner if the user chose rock
int userRock(int compChoice){
  if(compChoice == 1){
    return 0;
  }else if(compChoice == 2){
    return -1;
  }else{
    return 1;
  }
}
//function to determine winner if the user chose paper
int userPaper(int compChoice){
  if(compChoice == 1){
    return 1;
  }else if(compChoice == 2){
    return 0;
  }else{
    return -1;
  }
}
//function to determine winner if the user chose scissors
int userScissors(int compChoice){
  if(compChoice == 1){
    return -1;
  }else if(compChoice == 2){
    return 1;
  }else{
    return 0;
  }
}


int main(){
  //declare variables
  int user_Input;
  int comp_Choice;
  int timesPlayed = 0;
  int timesWon;
  //create input file object and open RPS.txt
  ifstream myFile ("RPS.txt");
  //if RPS.txt does not exsist create it and write in two 0's
  if(!myFile){
    ofstream newFile ("RPS.txt");
    newFile << 0 << endl;
    newFile << 0;
    newFile.close();
  }else{ //if the files does exsist get the timesPlayed and timesWon from its two lines
    myFile >> timesPlayed;
    myFile >> timesWon;
    myFile.close();
  }

  //do while statement for main code so it runs at least once
  do{
      //resets the random number generator
      seedRandom();
      comp_Choice = getRandomInt(1,4); //uses the random.cpp to generate a random number between 1 and 3

      /*prompt user input by giving the user the option of Rock, Paper, or Scissors;
        is inside a do while, so it has input validation, and if the input is not
        valid it will countinue to ask for input till its given valid input*/
      do{
        cout << "Welcome to Roshambo. Please select your choice from the options below:\n";
        cout << "1. Rock\n2. Paper\n3. Scissors\n4. Quit\nChoice: ";
        cin >> user_Input; //sets the value of the integer user_Input to the user's choice
        if(user_Input > 4 || user_Input <= 0){ //input validation (input must be 1, 2, 3, or 4)
            cout << "Not a choice! >__<\n";
        }
      }while(user_Input <= 0 || user_Input > 4);

      if(user_Input == 4){ //quits the program if the user input is 4
      }else if(user_Input == 1){ //runs when user picked rock
        if(userRock(comp_Choice) == 1){ //uses function to determine winner
          cout << "You chose Rock, the computer chose Scissors. You win!\n";
          timesWon++; //adds one to timesWon documentation
        }else if(userRock(comp_Choice) == -1){
          cout << "You chose Rock, the computer chose Paper. You lose :(.\n";
        }else{
          cout << "You both chose Rock. Tie!\n";
        }
      }else if(user_Input == 2){ //runs when user picked paper
        if(userPaper(comp_Choice) == 1){ //uses function to determine winner
          cout << "You chose Paper, the computer chose Rock. You win!\n";
          timesWon++; //adds one to timesWon documentation
        }else if(userPaper(comp_Choice) == -1){
          cout << "You chose Paper, the computer chose Scissors. You lose :(\n";
        }else{
          cout << "You both chose Paper. Tie!\n";
        }
      }else{ //runs when user picked scissors
        if(userScissors(comp_Choice) == 1){ //uses function to determine winner
          cout << "You chose Scissors, the computer chose Paper. You win!\n";
          timesWon++; //adds one to timesWon documentation
        }else if(userScissors(comp_Choice) == -1){
          cout << "You chose Scissors, the computer chose Rock. You lose :(.\n";
        }else{
          cout << "You both chose Scissors. Tie!\n";
        }
      }
      cout << endl; //prints a blank line for formatting purposes
      //adds one to times played for documentation purposes
      timesPlayed++;
    }while(user_Input < 4); //stops playing when the user inputs 4
  //creates output file objext and opens it to RPS.txt
  ofstream myOFile ("RPS.txt");
  myOFile << timesPlayed << endl; //prints timesPlayed to first line in RPS.txt
  myOFile << timesWon; //prints timeWon to the second line in RPS.txt
  myOFile.close(); //closes the output file object
  cout << "You've played " << timesPlayed << " time(s)!\n"; // Displays to the user how many times they've played
  cout << "You've won " << timesWon << " time(s)!\n"; //Displays to the user how many times they've won
  return 0;
}
