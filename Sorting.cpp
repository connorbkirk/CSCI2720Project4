// Question, do we want these function to be templates?
// What kind of overhead are we adding to each function?
// Will each new instance of the function with a specified data type add time? Maybe

template <typename T> 
void bubbleSort(T * array, int length){

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
void insertionSort(T * array, int length){
  bool finished = false;
  int current = length-1;
  bool moreToSearch = (current!=startIndex);
  
  while(moreToSearch && !finished){
    if(values[current] < values[current-1]){
      T temp = array[current];
      array[current] = array[current-1];
      array[current-1] = temp;

      current--;
      moreToSearch = (current != startIndex);
    }
    else
      finished = true;
  }
}
