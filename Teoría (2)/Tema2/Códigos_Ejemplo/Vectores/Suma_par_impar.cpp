#include <iostream>
using namespace std;

int main() {

    const int n = 10;
int A[n] = { 5, 3, 2, 1, 5, 1, 4, 2, 1, 6 };
int suma_pares = 0, suma_impares = 0;
  
for (int i = 0; i < n; i++)
  if (i % 2 == 0) suma_pares += A[i];
  else            suma_impares += A[i];

cout << "Suma pares = " << suma_pares << endl;
cout << "Suma impares = " << suma_impares << endl;
}