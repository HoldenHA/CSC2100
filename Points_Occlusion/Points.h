/*
  Holden Ayers
  4.12.2017
  Dr.Brown CSC 2100
  Program 4: Points and Occlusion
*/

using namespace std; //to avoid typing std

 //include guard
#if !defined POINTS_H
#define POINTS_H

#include "Point.h" //to access functions of Point

//defines a Points a Point array and the numOfPoints in that array (size)
struct Points{
  Point** items;
  int numOfPoints;
};

//function prototype for createPoints: creates a Points instance using the user provided file
Points* createPoints (const char* filename);
//function prototype for displayPoints: displays each Point in p
void displayPoints (Points* p);
//function prototype for destroyPoints: deletes each Point in p and p itself
void destroyPoints (Points* p);

#endif
