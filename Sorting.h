#ifndef __SORTING__
#define __SORTING__

// SORTING FUNCTION PROTOTYPES
template <typename T>
class Sorting{
 public:
  int BubbleSort(T *, int);
  int InsertionSort(T *, int);
  int SelectionSort(T *, int);

  int MergeSort(T *, int);
  int HeapSort(T *, int);
  int QuickSort(T *, int);
};

#endif
