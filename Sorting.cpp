// Question, do we want these function to be templates?
// What kind of overhead are we adding to each function?
// Will each new instance of the function with a specified data type add time? Maybe

template <typename T> 
void BubbleSort(T * array, int length){

	// You know the drill

	for(int i = length - 1; i >= 1; i--){

		for(int j  = 0; j < i; j++){
			
			if( array[j] > array[j+1] ){

				T temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
}

template <typename T>
void InsertionSort(T * array, int length){
  bool finished = false;
  int current = length-1;
  bool moreToSearch = (current!=0);
  
  while(moreToSearch && !finished){
    if(array[current] < array[current-1]){
      T temp = array[current];
      array[current] = array[current-1];
      array[current-1] = temp;

      current--;
      moreToSearch = (current != 0);
    }
    else
      finished = true;
  }
}

template <typename T>
void SelectionSort(T * array, int length){
  int endIndex = length-1;
  for(int current = 0; current < endIndex; current++){
    
    //calculate index of min val
    int indexOfMin = current;
    for(int index = current + 1; index <= endIndex; index++){
      if(array[index] < array[indexOfMin])
	indexOfMin = index;
    }

    //swap current with min
    T temp = array[current];
    array[current] = array[indexOfMin];
    array[indexOfMin] = temp;

  }
}


template <typename T>
void ReheapDown(T *& array, int root, int bottom){
  int maxChild, rightChild, leftChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;

  if(leftChild <= bottom){
    if(leftChild == bottom)
      maxChild = leftChild;
    else{
      if(array[leftChild] <= array[rightChild])
	maxChild = rightChild;
      else
	maxChild = leftChild;
    }
    if(array[root] < array[maxChild]){
      T temp = array[root];
      array[root] = array[maxChild];
      array[maxChild] = temp;

      ReheapDown(array, maxChild, bottom);
    }
  }
}



template <typename T>
void HeapSort(T * array, int length){
  int index;

  //convert array of values to a heap
  for(index = length/2-1; index >=0; index--)
    ReheapDown(array, index, length-1);

  //sort the array
  for(index = length-1; index >= 1; index--){
    T temp = array[0];
    array[0] = array[index];
    array[index] = temp;

    ReheapDown(array, 0, index-1);
  }
}
