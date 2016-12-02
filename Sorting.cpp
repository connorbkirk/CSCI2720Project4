#include "Sorting.h"

int comparisons;

int Sorting::BubbleSort(int * array, int length){
  // Function: This function takes two parameters, a pointer to
  //       an array of integers, and an int size. It sorts the
  //       array using bubble sort algorithm, and returns the
  //       number of comparisons.
  // Pre:  none.
  // Post: Adjacent pairs that are out of order have been switched
  //       between array[startIndex]..array[endIndex] beginning at
  //       array[endIndex].
  comparisons = 0;

  for(int i = length - 1; i >= 1; i--){
    
    for(int j  = 0; j < i; j++){
  
      comparisons++;
      if( array[j] > array[j+1] ){
	//swap
	int temp = array[j+1];
	array[j+1] = array[j];
	array[j] = temp;
      }
    }
  }

  return comparisons;
}

void InsertItem(int * array, int start, int end){
  // Function: This method takes three parameters, a pointer to
  //       an array of integers, an integer that represents start,
  //       and an integer that represents end. This method will then
  //       sort all elements from index start to index end.
  // Pre:  none
  // Post: array[0]..array[endIndex] are now sorted.
  bool finished = false;
  int current = end;
  bool moreToSearch = (current!=start);
  
  while(moreToSearch && !finished){
    comparisons++;
    if(array[current] < array[current-1]){
      int temp = array[current];
      array[current] = array[current-1];
      array[current-1] = temp;

      current--;
      moreToSearch = (current != start);
    }
    else
      finished = true;
  }

}

int Sorting::InsertionSort(int * array, int length){
  //Function: This method takes two parameters, a pointer to an array
  //       of integers and an integer that represents the size of the 
  //       array. It then calls InsertItem for all elements to sort
  //       the array and returns the number of comparisons.
  // Pre:  none.
  // Post: The elements in the array are sorted by key.
  comparisons = 0;
  for(int i = 0; i < length; i++)
    InsertItem(array, 0, i);
  return comparisons;
}

int Sorting::SelectionSort(int * array, int length){
  // Function: This method takes two parameters, a pointer to an array
  //       of integers and an integer that represents the size of the
  //       array. It then uses the selection sort algorithm to sort
  //       the values of the array and returns the number of comparisons.
  // Pre:  none.
  // Post: The elements in the array are sorted by key.
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
  // Function: Restores the order property of heaps to the tree 
  //       between root and bottom.
  // Pre:  The order property of heaps may be violated only by the 
  //       root node of the tree.
  // Post: The order property applies to all elements of the heap.
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
  // Function: This method takes two parameters, a pointer to an array         
  //       of integers and an integer that represents the size of the          
  //       array. It then uses the ReheapDown to convert the array to a heap
  //       and sorts the array which also calls on ReheapDown. This method
  //       then returns the number of comparisons.  
  // Pre:  none.
  // Post: The elements in the array are sorted by key.
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
	   int rightFirst, int rightLast, int length){
  // Function: This method takes 6 parameters - array of ints,
  //       leftFirst, leftLast, rightFirst, rightLast, and length
  //       leftFirst and leftLast are pointers to the first subarray
  //       rightFirst and rightLast are pointers to the second subarray.
  //       This method merges the two sorted subarrays into a single 
  //       sorted piece of the array.
  // Pre:  array[leftFirst]..array[leftLast] are sorted; 
  //       array[rightFirst]..array[rightLast] are sorted.
  // Post: array[leftFirst]..array[rightLast] are sorted.

  int * tempArray = new int[length];
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
  }
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

  for(index = saveFirst; index <= rightLast; index++)
    array[index] = tempArray[index];

  delete [] tempArray;
}

void DoMergeSort(int * array, int first, int last, int length){
  // Function: This method takes 4 parameters, a pointer to an array         
  //       of integers, an integer that represents the size of the          
  //       array, and integers that represent the first and last index
  //       to process. This method splits the array and calls Merge to
  //       merge the subarrays.
  // Pre:  none.
  // Post: the elements in array are sorted by key.
  if(first < last){
    int middle = (first + last) / 2;
    DoMergeSort(array, first, middle, length);
    DoMergeSort(array, middle + 1, last, length);
    Merge(array, first, middle, middle + 1, last, length);
  }
}

int Sorting::MergeSort(int * array, int length){
  // Function: This method takes two parameters, an array of ints, and an int
  //       representing its length. It makes the initial call to the recursive
  //       function DoMergeSort which sorts the given array using the 
  //       merge sort algorithm. Then this method returns the number of
  //       comparisons made.
  // Pre:  none.
  // Post: The elements in array are sorted by key.
  comparisons = 0;

  DoMergeSort(array, 0, length-1, length);
  return comparisons;
}

void Split(int * array, int first, int last, int & splitPt1,
	   int & splitPt2){
  // Function: This method takes 5 parameters: an array of ints,
  //       an int that reprents the first index, an int that
  //       represents the last index to be processed, an int that
  //       returns the split pointer 1, and an int that returns the 
  //       split pointer 2. This method will then split the array
  //       at the pivot and sort.
  // Pre:  none.
  // Post: array[first]...array[last] is in its correct position.

  int splitVal = array[(first+last)/2];

  bool onCorrectSide;

  do{
    onCorrectSide = true;
    
    while(onCorrectSide){
      comparisons++; 
      if(array[first] >= splitVal)
     	onCorrectSide = false;
      else
	first++;
    }

    onCorrectSide = true;
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
  // Function: This method takes 3 parameters: an array of ints,
  //       an int that represents the first index to process, and 
  //       and int that represents the last index to process. This
  //       method then calculates pivot points and calls Split to sort.
  // Pre:  first and last are within the bounds of the array.
  // Post: The array is sorted.

  comparisons++;
  if(first < last){
    int splitPt1, splitPt2;

    Split(array, first, last, splitPt1, splitPt2);
    // array[first]..array[splitPt2] <= splitVal
    // array[splitPt1+1]..array[last] > splitVal

    comparisons++;
    if(splitPt1 < last)
      DoQuickSort(array, splitPt1, last);

    comparisons++;
    if(first < splitPt2)
      DoQuickSort(array, first, splitPt2);
  }
}

int Sorting::QuickSort(int * array, int length){
  // Function: This function takes two parameters, a pointer to
  //       an array of integers, and an int size. It sorts the      
  //       array using quick sort algorithm, and returns the
  //       number of comparisons.    
  // Pre:  none.
  // Post: The array is sorted.
  comparisons = 0;
  DoQuickSort(array, 0, length-1);
  return comparisons;
}
