#include <iostream>
using namespace std;

int main() {
const int n = 10;
int A[n] = { 5, 3, 2, 1, 5, 1, 4, 2, 1, 6 };
int suma = 0;
  
for (int i = 0; i < n; i++)
  suma += A[i];

cout << "suma = " << suma << endl;

}