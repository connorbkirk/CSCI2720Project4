#include <iostream>
#include <array>
using namespace std;

int main(){
  int num;
  cin >> num;
  int stuff[num];//array to sort
  int safeStuff[num];//never to be changed, only to reset from
  for(int i = 0; i < num; i++){//fills array with information from file
    cin >> stuff[i];
    safeStuff[i] = stuff[i];
  }
}
