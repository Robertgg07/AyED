#include <iostream>
using namespace std;

int main() {
const int n = 10;
int A[n]; // int *A = new int[n];
  
for (int i = 0; i < n; i++)
  A[i] = i;
  
cout << "A: ";
for (int i = 0; i < n; i++)
  cout << A[i] << " ";
cout << endl;
//delete[] A;

}