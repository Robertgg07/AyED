#include <iostream>
#include <cmath>

using namespace std;

int main() {
const int n = 10;
int A[n] = { 5, 3, 2, 1, 5, 1, 4, 2, 1, 6 };
// INFINITY definida en cmath
int min = INFINITY , max = -INFINITY;
  
for (int i = 0; i < n; i++) {
  if (A[i] < min) min = A[i];
  if (A[i] > max) max = A[i];
}

cout << "min = " << min << endl;
cout << "max = " << max << endl;

}