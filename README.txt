CSCI 2720 Project 3
12/1/16

--------------------------

Group members:
Carter Hart
Andrew Durden
Connor Kirk

--------------------------

To compile our code type:
   $ make compile

--------------------------

To run the code type:
   $ make run

---------------------------

To clean the directory type:
   $ make clean

----------------------------

To compile gen.cpp:
   $ g++ -std=gnu++11 -o gen.out

----------------------------

To run gen.out type:

   ./gen.out [size n] [flag] [-n for naming the file followed by] [String filename]

   flag options:
        -s outputs a sorted file
        -r outputs a file with numbers sorted in reverse
        [nothing] outputs a file with random numbers between 1 and n, without repeats

	-n flag is optional, but if it is there it must be followed by a filename

    Exmaple:

    ./gen.out 100 -r -n reverse.dat
  
    // outputs 100 to 0 in file reverse.dat

---------------------------

Directory contents:
	  Sorting.h	-header file for sorting algorithm class
	  Sorting.cpp	-implementation of sorting algorithms
	  gen.cpp	-generates our data files
	  main.cpp	-driver file for teting algorithms
