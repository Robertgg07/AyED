#include <iostream>
using namespace std;

int main() {
const int n = 3;
int A[n] = { 5, 3, 2 }, B[n] = { 1, 5, 1 };
int producto_escalar = 0;
  
for (int i = 0; i < n; i++)
  producto_escalar += A[i] * B[i];
    
cout << "Producto escalar = " << producto_escalar
     << endl;
}     