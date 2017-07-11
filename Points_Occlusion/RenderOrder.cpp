/*
  Holden Ayers
  4.12.2017
  Dr.Brown CSC 2100
  Program 4: Points and Occlusion
*/

#include <iostream> //for i/o
#include <fstream> //for input file
#include <cmath> //for math functions
#include "Points.h" //for making Points
#include "Point.h" //for reference point

using namespace std; //to avoid having to type std

float distanceFromRefPoint (Point* p, Point refPoint){
  //function using the pythagorean theory to calculate distance
  return sqrt( pow((refPoint.x - p->x), 2) + pow((refPoint.y - p->y), 2) + pow((refPoint.z - p->z), 2) );
}

void sortPointsByDistance (Points* p, Point refPoint){
  /*
  uses bubble Sort to sort Points array
  instead of comparing elements of Points,
  compares the distance of the points from reference points,
  the distance from the reference point of point j is compared to the distance from the reference point of point i
  */

  int min;
	Point* swap;
  int size = p->numOfPoints;

	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
      //compares the distances from the reference point rather than the actual element a i/j
			if ( distanceFromRefPoint(p->items[j],refPoint) < distanceFromRefPoint(p->items[i],refPoint))
			{
				 min = j;
			}
		}

		swap =  p->items[min];
		p->items[min] =  p->items[i];
		p->items[i] = swap;
  }
}


int main(int argc, char* argv[]){ //gets command line arguments
  ifstream inFile; //creates input file object
  Point refPoint; //creates the reference point using the point struct
  //verifies that the user inputted the correct command line arguments
  if(argc != 5){
    cout << "\nInvalid call format.  Please include all required information." << endl;
    cout << "Format: Main.exe <Points File> <Ref X> <Ref Y> <Ref Z>" << endl;
    return 1;
  }

  //sets the members of the reference point to the values provided in the command line
  refPoint.x = atof(argv[2]);
  refPoint.y = atof(argv[3]);
  refPoint.z = atof(argv[4]);

  //opens the file passed through the command line
  inFile.open(argv[1]);
  //verifies that the file name was valid
  if(!inFile){
    cout << "\nInvalid Input.  File does not exist.  Please try fixing and rerun program" << endl;
    return 1;
  }
  //creates new Points array using file from command line
  Points* myPoints = createPoints(argv[1]);
  //displays the unsorted array
  cout << "Unsorted:\n";
  displayPoints(myPoints);
  cout << endl;
  //sorts the Points array and then prints it
  sortPointsByDistance(myPoints, refPoint);

  cout << "Sorted:\n";
  displayPoints(myPoints);

  //destroy the points to avoid memory issues
  destroyPoints(myPoints);
}
