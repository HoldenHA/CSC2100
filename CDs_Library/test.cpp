using namespace std;
#include "CD.h"
#include <fstream>
#include <string>
#include <iostream>

int main(){
  string artist,  cdTitle, songName, songLength;
  int releaseYear, cdRating, numOfSongs, myCounter = 0,sizer = 10000 ;
  CD** temps = new CD*[sizer];

  ifstream myFile;
  myFile.open("songs.txt");


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


  for(int k = 0; k < myCounter; k++){
    displayCD(temps[k]);

  }
}
