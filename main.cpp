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

  // INIT SOME PARAMS
	
  int cmd;
  int num;
  string filename;
  Sorting sorting;

  // GET DESIRED LENGTH BASED O 

  cout << "Enter Length of array (10, 100, 500, 1000, 10000, 20000, 100000, 200000)\n";
  cin >> num;

  cout << endl;

	cout << "Select a pattern:\n";
  cout << "1) Sorted\n" << "2) Random\n" << "3) Reversed\n";
  cin >> cmd;

  if(cmd == 1){

	filename = "inorder.dat";

  } else if(cmd == 2){
	
	filename = "random.dat";

  } else if(cmd == 3){
	
	filename = "reverse.dat";

  } else {

	cout << "ERROR: INPROPER COMMAND\n";
	return 0;

  }


//This is the main driver program for our project

	fstream input(filename.c_str(), ios_base::in);



// CREATES ARRAY TO SORT AND COPY SO IT CAN BE REVERTED

int stuff[num];

int safeStuff[num];//never to be changed, only to reset from



// FILLS ARRAY WITH FIRST NUM ITEMS IN FILE

int count = 0;
int a;

//cout << "File content:\n";

while(input >> a){
  if(count == num) break;
  stuff[count] = a;
  //cout << a << " ";
  count++;
 }

for(int i = 0; i < num; i++){
  //fills array with information from file
  safeStuff[i] = stuff[i];
 }

//cout << "\nArray:\n";
//printArray(stuff, num);

cout << endl << endl;

//---------------------- 

//TIME VARIABLES
clock_t begin;
clock_t end;
double elapsedTime;


//----------------------
// BUBBLE SORT
//----------------------
cout << "Bubble Sort:\n";

begin = clock();
cout << "Numer of comparisons: " << sorting.BubbleSort(stuff, num) << endl;
end = clock();
elapsedTime = double(end-begin) / CLOCKS_PER_SEC * 1000;
cout << "Elapsed time: " << elapsedTime << "ms\n";
cout << "\n\n";

revert(stuff, safeStuff, num);  

//---------------------- 
// INSERTION SORT
//---------------------- 
cout << "Insertion Sort:\n";

begin = clock();
cout << "Numer of comparisons: " << sorting.InsertionSort(stuff, num) << endl;
end = clock();
elapsedTime = double(end-begin) / CLOCKS_PER_SEC * 1000;
cout << "Elapsed time: " << elapsedTime << "ms\n";
cout << "\n\n";

revert(stuff, safeStuff, num);  

//---------------------- 
// SELECTION SORT
//---------------------- 
cout << "Selection Sort:\n";

begin = clock();
cout << "Numer of comparisons: " << sorting.SelectionSort(stuff, num) << endl;
end = clock();
elapsedTime = double(end-begin) / CLOCKS_PER_SEC * 1000;
cout << "Elapsed time: " << elapsedTime << "ms\n";
cout << "\n\n";

revert(stuff, safeStuff, num);  

//---------------------- 
// MERGE SORT
//---------------------- 
cout << "Merge Sort:\n";

begin = clock();
cout << "Numer of comparisons: " << sorting.MergeSort(stuff, num) << endl;
end = clock();
elapsedTime = double(end-begin) / CLOCKS_PER_SEC * 1000;
cout << "Elapsed time: " << elapsedTime << "ms\n";
cout << "\n\n";

revert(stuff, safeStuff, num);  

//---------------------- 
// HEAP SORT
//---------------------- 
cout << "Heap Sort:\n";

begin = clock();
cout << "Numer of comparisons: " << sorting.HeapSort(stuff, num) << endl;
end = clock();
elapsedTime = double(end-begin) / CLOCKS_PER_SEC * 1000;
cout << "Elapsed time: " << elapsedTime << "ms\n";
cout << "\n\n";

revert(stuff, safeStuff, num);  

//---------------------- 
// QUICK SORT
//---------------------- 
cout << "Quick Sort:\n";

begin = clock();
cout << "Numer of comparisons: " << sorting.QuickSort(stuff, num) << endl;
end = clock();
elapsedTime = double(end-begin) / CLOCKS_PER_SEC * 1000;
cout << "Elapsed time: " << elapsedTime << "ms\n";
cout << "\n\n";

revert(stuff, safeStuff, num);

input.close();

return 0 ;



}
