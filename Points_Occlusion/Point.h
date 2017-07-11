/*
  Holden Ayers
  4.12.2017
  Dr.Brown CSC 2100
  Program 4: Points and Occlusion
*/

using namespace std; //to avois typing std

//include guard
#if !defined POINT_H
#define POINT_H

//struct that defines a Point as 3 doubles containing X, Y, and Z values
struct Point{
  double x;
  double y;
  double z;
};

//function prototype for createPoint: creates a Point with passed X,Y, and Z values
Point* createPoint (double x, double y, double z);
//function prototype for displayPoint: displays passed point p to command line
void displayPoint (Point* p);
//function prototype for destroyPoint: destroys dynamically allocated point p
void destroyPoint (Point* p);

#endif
