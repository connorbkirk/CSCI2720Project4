#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Sorting.h"

using namespace std;

// PROTOTYPES

template <typename T> void randomizeArray(T *, int);
template <typename T> void printArray(T *, int);



// MAIN

int main(){

	cout << endl;	

	// Allocate space
	int length = 15;
	int * array = new int[length];


	randomizeArray(array, length);

	printArray(array, length);

	bubbleSort(array, length);

	printArray(array, length);


	// Deallocate space	
	delete[] array;
	return 0;
}



// FUNCTIONS

template <typename T> void randomizeArray(T * array,int length){

	// Honestly this technique could just be run once to write 200,000
	// random ints into a file for the project.

	// Defines range from 1 to 100
	int max = 100;
	int min = 1;


	// Seeds the random variable
    srand(time(0));

	int a = 0;

	for(int i = 0; i < length; i++){

    	a = rand();

		// converts huge number to be of range [1, 100]
		a = a % max + min;

		array[i] = a;
	}	
}

template <typename T> void printArray(T * array,int length){

	for(int i = 0; i < length; i++)
        cout << array[i] << " ";
    cout << endl << endl;

}
