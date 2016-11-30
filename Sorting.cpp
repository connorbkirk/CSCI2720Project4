// Question, do we want these function to be templates?
// What kind of overhead are we adding to each function?
// Will each new instance of the function with a specified data type add time? Maybe

#include "Sorting.h"
#include <iostream>

using namespace std;

int comparisons;

int Sorting::BubbleSort(int * array, int length){
  comparisons = 0;
  for(int i = length - 1; i >= 1; i--){
    
    for(int j  = 0; j < i; j++){
      
      comparisons++;
      if( array[j] > array[j+1] ){
	int temp = array[j+1];
	array[j+1] = array[j];
	array[j] = temp;
      }
    }
  }

  return comparisons;
}

int Sorting::InsertionSort(int * array, int length){
  comparisons = 0;
  bool finished = false;
  int current = length-1;
  bool moreToSearch = (current!=0);
  
  while(moreToSearch && !finished){
    comparisons++;
    if(array[current] < array[current-1]){
      int temp = array[current];
      array[current] = array[current-1];
      array[current-1] = temp;

      current--;
      moreToSearch = (current != 0);
    }
    else
      finished = true;
  }
  return comparisons;
}

int Sorting::SelectionSort(int * array, int length){
  int endIndex = length-1;
  for(int current = 0; current < endIndex; current++){
    
    //calculate index of min val
    int indexOfMin = current;
    for(int index = current + 1; index <= endIndex; index++){
      comparisons++;
      if(array[index] < array[indexOfMin])
	indexOfMin = index;
    }

    //swap current with min
    int temp = array[current];
    array[current] = array[indexOfMin];
    array[indexOfMin] = temp;

  }
  return comparisons;
}


void ReheapDown(int *& array, int root, int bottom){
  int maxChild, rightChild, leftChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;

  comparisons++;
  if(leftChild <= bottom){
    comparisons++;
    if(leftChild == bottom)
      maxChild = leftChild;
    else{
      comparisons++;
      if(array[leftChild] <= array[rightChild])
	maxChild = rightChild;
      else
	maxChild = leftChild;
    }
    comparisons++;
    if(array[root] < array[maxChild]){
      int temp = array[root];
      array[root] = array[maxChild];
      array[maxChild] = temp;

      ReheapDown(array, maxChild, bottom);
    }
  }
}


int Sorting::HeapSort(int * array, int length){
  int index;
  comparisons=0;
  //convert array of values to a heap
  for(index = length/2-1; index >=0; index--)
    ReheapDown(array, index, length-1);

  //sort the array
  for(index = length-1; index >= 1; index--){
    int temp = array[0];
    array[0] = array[index];
    array[index] = temp;

    ReheapDown(array, 0, index-1);
  }

  return comparisons;
}

void Merge(int * array, int leftFirst, int leftLast, 
	   int rightFirst, int rightLast){
  // Post: array[leftFirst]..array[leftLast] and
  //       array[rightFirst]..array[rightLast] have been merged.
  //       array[leftFirst]..array[rightLast] are now sorted.

  int * tempArray = new int[200000];
  int index = leftFirst;
  int saveFirst = leftFirst;

  while((leftFirst<=leftLast) && (rightFirst<=rightLast)){
    comparisons++;
    if( array[leftFirst] < array[rightFirst]){
      tempArray[index] = array[leftFirst];
      leftFirst++;
    }
    else{
      tempArray[index] = array[rightFirst];
      rightFirst++;
    }
    index++;

    while(leftFirst <= leftLast){
      //Copy remaining items from left half.
      tempArray[index] = array[leftFirst];
      leftFirst++;
      index++;
    }

    while(rightFirst <= rightLast){
      //Copy remaining items from right half.
      tempArray[index] = array[rightFirst];
      rightFirst++;
      index++;
    }
  }

  for(index = saveFirst; index <= rightLast; index++)
    array[index] = tempArray[index];

  delete [] tempArray;
}

void DoMergeSort(int * array, int first, int last){
  //Post: the elements in array are sorted by key.
  if(first < last){
    int middle = (first + last) / 2;
    DoMergeSort(array, first, middle);
    DoMergeSort(array, middle + 1, last);
    Merge(array, first, middle, middle + 1, last);
  }
}

int Sorting::MergeSort(int * array, int length){
  comparisons = 0;

  DoMergeSort(array, 0, length-1);
  return comparisons;
}

void Split(int * array, int first, int last, int & splitPt1,
	   int & splitPt2){
  int splitVal = array[(first+last)/2];

  bool onCorrectSide;

  do{
    onCorrectSide = true;
    
    comparisons++;
    while(array[first] >= splitVal){
      
      comparisons+=2; //one for while and one for if
      //move first toward last
      
      if(array[first] >= splitVal)
     	onCorrectSide = false;
      else
	    first++;
    }

    onCorrectSide = true;
    
    comparisons++;
    while(onCorrectSide){
      //move last toward first
      comparisons++;
      if(array[last] <= splitVal)
     	onCorrectSide = false;
      else
     	last--;
    }

    comparisons++;
    if(first <= last){
      int temp = array[first];
      array[first] = array[last];
      array[last] = temp;

      first++;
      last--;
    }

  }while(first <= last);

  splitPt1 = first;
  splitPt2 = last;
}

void DoQuickSort(int * array, int first, int last){
  
  comparisons++;
  if(first < last){
    int splitPt1, splitPt2;

    Split(array, first, last, splitPt1, splitPt2);

    comparisons++;
    if(splitPt1 < last)
      DoQuickSort(array, splitPt1, last);

    comparisons++;
    if(first < splitPt2)
      DoQuickSort(array, first, splitPt2);
  }
}

int Sorting::QuickSort(int * array, int length){
  //This is the algorithm that is more
  //space efficient O(logN)

  cout << "inside quicksort" << endl;

  comparisons = 0;
  DoQuickSort(array, 0, length-1);
  return comparisons;
}
