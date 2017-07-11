/*
  Holden Ayers
  4.12.2017
  Dr.Brown CSC 2100
  Program 4: Points and Occlusion
*/

#include <fstream> //for input file
#include <iostream> //for i/o
#include "Points.h" //for making use of Points and Point

using namespace std; //to avoid having to type std

//function to create a Points array of Points using Point and Points structs
Points* createPoints (const char* filename){
  int size; //size provided in user provided file
  double x = 0.0,y = 0.0 , z = 0.0; //variables for making points

  ifstream myFile (filename); //opens user provided file

  myFile >> size; //gets the number of points to create from the user file

  Point** pnts = new Point*[size]; //creates a dynamically allocated array of Points using the size that the user provided

  //goes through the input file and pulls out each point according to the size that the user provided on the first line of the file
  for(int i = 0; i < size; i++){
    myFile >> x; //gets x member of point from file
    myFile >> y; //gets y member of point from file
    myFile >> z; //gets z member of point from file
    pnts[i] = createPoint (x, y, z); //puts the point into the array at position i
  }

//creates a Points object and sets it's members to the array set above and to the user provided size
 Points* pts = new Points;
 pts->items = pnts;
 pts->numOfPoints = size;

 //returns the Points object that contains all the points from the user file
 return pts;
}
//function to display Points
void displayPoints (Points* p){
  //gets the Number of points from the numOfPoints member of p
  int arrSize = p->numOfPoints;

  //displays each point in the items member of p, using the Point functions
  for(int i = 0; i < arrSize; i++){
    displayPoint (p->items[i]);
  }
}

//destroys points to avoid memory issues
void destroyPoints (Points* p){
  //gets the Number of points from the numOfPoints member of p
  int arrSize = p->numOfPoints;

  //destroys each point in the items member of p
  for(int i = 0; i < arrSize; i++){
    destroyPoint(p->items[i]);
  }

  //deletes items member of p
  delete[] p->items;

  //deletes p
  delete p;
}
