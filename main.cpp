#include <iostream>
#include <fstream>
#include <ctime>

#include "Sorting.h"

using namespace std;
void printArray(int* array, int length){
  for(int i = 0; i < length; i++)
    cout << array[i] << " ";
  cout << endl << endl;
}

void revert(int*array, int* safe, int length){
  for(int i =0;i<length; i++)
    array[i] = safe[i];
}

int main(int argc, char * argv[]){

  int num;
  Sorting sorting;

  cout << "Enter Length of array: ";
  cin >> num;

  int stuff[num];//array to sort

  int safeStuff[num];//never to be changed, only to reset from

  for(int i = 0; i < num; i++){//fills array with information from file
	cout << "array["<< i <<"] = ";
    cin >> stuff[i];
    safeStuff[i] = stuff[i];
  }

  cout << "Your Array: \n";

  printArray(stuff, num);
 
  clock_t begin = clock();

  cout << "Numer of comparisons: " << sorting.BubbleSort(stuff, num) << endl;

  clock_t end = clock();
  double elapsedTime = double(end-begin) / CLOCKS_PER_SEC * 1000;

  cout << "Elapsed time: " << elapsedTime << "ms\n";

  cout << "Sorted Array: \n";

  printArray(stuff, num);
 
  //revert(stuff,safeStuff,num); reverts array back for the rest of the sort calls



  

}
