//declare preprocessor directive 
#include "Statistics.h"
//namespace std for easy coding
using namespace std;

//quickSort function for easy sorting on provided array
void quickSort(float arr[], int left, int right) {
      int i = left, j = right;
      float tmp;
      float pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
//function to find mode of provided array; with provided size 
int findMode (float numbers[], int size){
  //declare variables for findMode function
  int _mode;
  int counter;
  int max = 0;
  //mode algorithm 
  for (int pass = 0; pass < size-1; pass++)
       {
          if (numbers[pass] == numbers[pass+1])
          {
             counter++;
             if ( counter > max )
             {
                 max = counter;
                 _mode = numbers[pass];
             }
          } else
             counter = 1; // reset counter.
       }
	//returns the found mode
    return _mode;
}
//function to find median of provided array; with provided size 
float findMedian (float numbers[], int size){
  //declare variables for findMedian function
  float _median;
  int spot1;
  int spot2;
  //median algorithm 
  if(size % 2 == 0){
    spot1 = size / 2;
    spot2 = (size / 2) + 1;
    _median = (numbers[spot1] + numbers[spot2]) / 2;
  }else{
    _median = numbers[(size + 1)/2];
  }
  //returns the found median
  return _median;

}
//function to find mean of provided array; with provided size 
float findMean (float numbers[], int size){
  //declare variables for findMean function
  float _mean;
  //mean algorithm
  for(int i = 0; i <= size; i++){
    _mean += numbers[i];
  }
  //returns the found mean
  return _mean / size;
}
