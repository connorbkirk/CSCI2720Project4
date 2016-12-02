//This is the main driver program for our project

#tream input(filename.c_str(), ios_base::in);



// CREATES ARRAY TO SORT AND COPY SO IT CAN BE REVERTED

int stuff[num];

int safeStuff[num];//never to be changed, only to reset from



// FILLS ARRAY WITH FIRST NUM ITEMS IN FILE

int count = 0;
int a;

cout << "File content:\n";

while(input >> a){
  if(count == num) break;
  stuff[count] = a;
  cout << a << " ";
  count++;
 }

for(int i = 0; i < num; i++){//fills array with information from file
  safeStuff[i] = stuff[i];
 }
cout << "\nArray:\n";
printArray(stuff, num);

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




/*


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
  
  */
}
