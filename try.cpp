#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  
  int x;
  myfile.open ("example.txt");
  cout<< "Enter number";
  cin >>x; 
  myfile << x;
  myfile.close();
  return 0;
}