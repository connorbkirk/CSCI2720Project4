#include <iostream>
#include <array>
#include "Sorting.h"

using namespace std;
void printArray(int* array, int length){
  for(int i = 0; i < length; i++)
    cout << array[i] << " ";
  cout << endl << endl;
}

void revert(int*array, int* safe, int length){
  for(int i =0;i<legnth; i++)
    array[i] = safe[i];
}

int main(){
  int num;
  cin >> num;
  int stuff[num];//array to sort
  int safeStuff[num];//never to be changed, only to reset from
  for(int i = 0; i < num; i++){//fills array with information from file
    cin >> stuff[i];
    safeStuff[i] = stuff[i];
  }
  //timestamp
  bubbleSort(stuff, num);
  //timestamp
  //revert(stuff,safeStuff,num); reverts array back for the rest of the sort calls


}
