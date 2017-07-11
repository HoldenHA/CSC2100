using namespace std;
#include "CDs.h"
#include <fstream>
#include <string>
#include <iostream>

CDs* createCDs (const char* filename){
  string artist,  cdTitle, songName, songLength, tmp;
  int releaseYear, cdRating, numOfSongs, myCounter = 0, sizer = 0 ;

  ifstream myFile;
  myFile.open(filename);

  for(tmp; getline(myFile, tmp); )
      sizer++;

  CD** temps = new CD*[sizer];

  myFile.close();
  myFile.open(filename);
  for(artist; getline(myFile, artist); ){
    getline(myFile, cdTitle);
    myFile >> releaseYear;
    myFile >> cdRating;
    myFile >> numOfSongs;
    temps[myCounter] = createCD(artist, cdTitle, releaseYear, cdRating, numOfSongs);

    myFile.ignore();

    for(int i = 0; i < numOfSongs; i++){
      getline(myFile, songLength);
      getline(myFile, songName);
      temps[myCounter]->__songs[i] = createSong(songName, songLength);
    }
    myCounter++;
  }
  CDs* myCDs = new CDs;

  myCDs->___cdArray = temps;
  myCDs->___currentSize = myCounter;
  myCDs->___maxSize = sizer;

  return myCDs;
}

void displayCDs (CDs* c){
  int arrSize = c->___currentSize;

  for(int i = 0; i < arrSize; i++){
    displayCD(c->___cdArray[i]);
  }
}

void destroyCDs (CDs* c){
  int arrSize = c->___currentSize;

  for(int i =0; i < 0; i++){
    destroyCD(c->___cdArray[i]);
  }

  delete c;
}

CDs* findCDs (CDs* cds, string artist){
  int arrSize = cds->___currentSize;
  int myCounter = 0;
  CDs*  artistsCDs = new CDs;
  artistsCDs->___cdArray = new CD*[arrSize];

  for(int i = 0; i < arrSize; i++){
    if(cds->___cdArray[i]->__artist == artist){
      artistsCDs->___cdArray[myCounter] = cds->___cdArray[i];
      myCounter++;
    }
  }

  artistsCDs->___maxSize = arrSize;
  artistsCDs->___currentSize = myCounter;

  return artistsCDs;
}
