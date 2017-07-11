/*
  Holden Ayers
  2.6.2017
  Lab 1 - Roshambo
*/

//import the required C++ library, and the required header file
#include <iostream>
#include "Random.h"

//use namespace standard so you don't have to keep typing "std"
using namespace std;

int main()
{
    //resets the random number generator
    seedRandom();

    //declare our variables
    int user_Input; //sets an integer for the user's choice of Rock, Paper, or Scissor
    int comp_Choice = getRandomInt(1,4); //uses the random.cpp to generate a random number between 1 and 3

    //prompt user input by giving the user the option of Rock, Paper, or Scissors
    cout << "Welcome to Roshambo. Please select your choice from the options below\n 1. Rock\n 2. Paper\n 3. Scissors\nChoice : ";
    cin >> user_Input; //sets the value of the integer user_Input to the user's choice

    //conditional statements
    if(user_Input >= 4 || user_Input <= 0){ //input validation (input must be 1, 2 or 3)
        cout << "Not a choice. Goodbye.\n";
    }else if(user_Input == 1){ //runs if the user chose rock
        if(comp_Choice == 1){ //runs if the computer chose rock
            cout << "You both chose Rock. Tie!\n";
        }else if(comp_Choice == 2){ //runs if the computer chose paper
            cout << "You chose Rock, the computer chose Paper. You lose :(.\n";
        }else{ //runs if the computer chose scissors
            cout << "You chose Rock, the computer chose Scissors. You win!\n";}
    }else if(user_Input == 2){ //runs if the user chose paper
        if(comp_Choice == 1){ //runs if the computer chose rock
            cout << "You chose Paper, the computer chose Rock. You win!\n";
        }else if(comp_Choice == 2){ //runs if the computer chose paper
            cout << "You both chose Paper. Tie!\n";
        }else{ //runs if the computer chose scissors
            cout << "You chose Paper, the computer chose Scissors. You lose :(\n";}
    }else{ //runs if the user chose scissors
        if(comp_Choice == 1){//runs if the computer chose rock
            cout << "You chose Scissors, the computer chose Rock. You lose :(.\n";
        }else if(comp_Choice == 2){ //runs if the computer chose paper
            cout << "You chose Scissors, the computer chose Paper. You win!\n";
        }else{ //runs if the computer chose scissors
            cout << "You both chose Scissors. Tie!\n";}
    }

    return  0; //used for debugging
}
