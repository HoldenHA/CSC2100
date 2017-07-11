/*
  Holden Ayers
  4.12.2017
  Dr.Brown CSC 2100
  Program 4: Points and Occlusion
*/

#include <iostream> //for i/o
#include "Point.h" //to access header of Point

using namespace std; //to avoid having to typer std

//creates a new Point object using the Point struct
Point* createPoint (double x, double y, double z){
  //creates a new dynamically allocated instance of p
  Point* p = new Point;
  p->x = x; //sets the x member of p to x from function call
  p->y = y; //sets the y member of p to y from function call
  p->z = z; //sets the z member of p to z from function call

  //returns point p
  return p;
}

//used to display one point
void displayPoint (Point* p){
  //prints to command prompt the X, Y, and Z member's of p
  cout << "(" << p->x << ", " << p->y << ", " << p->z << ")\n";
}

//deletes a point to avoid memory issues
void destroyPoint (Point* p){
  //deletes the dynamically allocated p
  delete p;
}
