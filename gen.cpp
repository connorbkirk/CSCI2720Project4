// to use call ./out [int number of ints in file] [either -r(reversed order sorted) or -s(in order sorted) or no flag] 
//    [-n next item will be name of txt file] [string name of txt file (only if preceded by "-n" flag)]
// i.e. ./out 10 -s -n "filename.txt" (either flag may be omitted, -s may be replaced with -r) MUST BE IN ORDER

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


int getRand(vector<int> & v){
  // Function: This method takes a vector as a parameter.
  //       It randomly selects a number, deletes it from the
  //       vector, and returns it.
  // Pre:  none.
  // Post: returns a randomly selected number from v.
  int i  = rand();
  i = i % v.size();

  int a = v[i];
  v.erase(v.begin() + i);

  return a;
}

void creatfile(int num, bool sorted, bool reverse, string name){
  // Function: This method takes 4 parameters: the number of 
  //       integers, a bool telling whether or not the data
  //       should be sorted, a bool telling if the data should
  //       be reversed, and the name of the file to create. This
  //       method then creates a file of random integers pertaining
  //       to that criteria.
  // Pre:  None.
  // Post: A file is created with the given name, with the the 
  //       specified constraints.
  
  vector<int> v;

  for(int i = 1; i <= num; i++){
     v.push_back(i);
  }
 
  ofstream myfile;

  myfile.open(name);
  
//  myfile << num << endl; //prints the numebr of data points on a line before the data

  srand(time(0));//seeds random generater

  for(int i =0; i<num;i++){

	//sorted will count from 1 to num
    if (sorted)
      myfile << (i+1);

	//reversed will count down from num to 1
    else if(reverse)
      myfile << num-i;

	//get random numbers to write to file
    else
      myfile << getRand(v);

    myfile << "\n";//deliminates by spaces
  }

  myfile.close();
}

int main(int argc, char* argv[]){
  // Function: this is the main method that genereates files.
  // Pre:  none.
  // Post: The required data files are created.
  bool sorted = false;  
  bool reverse = false;
  int num = 0;
  string name = "input.txt";
  
  try{
    num = stoi(argv[1]);
  }
  
  catch(invalid_argument){
    cout << "first element of the input must be numeric followed by flag";
  }
  
  if(argc >= 3 && strcmp(argv[2],"-s")==0){//data is to be sorted
    sorted = true;
  }
  else if(argc >= 3 && strcmp(argv[2],"-r")==0){//data is to be in reverse order
    reverse = true;
  }
  else if(argc == 4 && strcmp(argv[2],"-n")==0){//data not sorted and file is to be named
    name = argv[3];
  }
  
  if(argc == 5 && strcmp(argv[3],"-n")==0){//data is sorted and file is to be named
    name = argv[4];
  }
  
  creatfile(num,sorted,reverse,name);
  
}
    
  
