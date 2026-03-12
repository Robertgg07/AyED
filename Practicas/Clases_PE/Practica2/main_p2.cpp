/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file main_p2.cpp
  * @author Robert García García alu0101825878
  * @date March 11 2026
  * @brief Programa principal
  * @bug There are no known bugs
  * @see 
  *
  * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License 
  * as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
  */

#include <iostream>
#include <cmath>

#include "rational_t.hpp"
#include "vector_t.hpp"
#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3);

  /// Fase I
  cout << "a + b: ";
  (a+b).write();

  cout << "b - a: ";
  (b-a).write();

  cout << "a * b: ";
  (a*b).write();
  
  cout << "a / b: ";
  (a/b).write();
  
  cout << endl;
  
  /// Fase II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;
  
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl;
  
  /// Fase III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices entre A y B: " << endl;
  C.write();

  return 0;
}