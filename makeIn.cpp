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
using namespace std;
int getRand(int num){//gets a random number from 0 to num*100(lessens likelyhood of duplicates)
  int a  = rand();
  int max = num*100;
  a = a%max;
  return a;
}

void creatfile(int num, bool s, bool r,string name){//opens file and fills it
  ofstream myfile;
  myfile.open(name);
  srand(time(0));//seeds random generater
  for(int i =0; i<num;i++){
    if(s)//sorted will count from 0 to num -1
      myfile << i;
    else if(r)//reversed will count down from num to 1
      myfile << num-i;
    else
      myfile << getRand(num);//get random numbers to write to file
    myfile <<" ";//deliminates by spaces
  }
  myfile.close();
}

int main(int argc, char* argv[]){//reads flags and number of integers
  bool s = false;
  bool r = false;
  int num =0;
  string name = "input.txt";
  try{
    num = stoi(argv[1]);
  }
  catch(invalid_argument){
    cout << "first element of the input must be numeric followed by flag";
  }
  if(argc ==3 && strcmp(argv[2],"-s")==0){//data is to be sorted
    s =true;
  }
  if(argc ==3 && strcmp(argv[2],"-r")==0){//data is to be in reverse order
    r =true;
  }
  if(argc ==4 && strcmp(argv[2],"-n")==0){//data not sorted and file is to be named
    name = argv[3];
  }
  if(argc ==5 && strcmp(argv[3],"-n")==0){//data is sorted and file is to be named
    name = argv[4];
  }
  
  cout << argc <<" "<< r<< " "<< num <<endl;

  creatfile(num,s,r,name);
}
    
   
