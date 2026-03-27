/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file main_polynomial.cc
  * @author Robert García García alu0101825878
  * @date March 24 2026
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

#include "polynomial.h"

using namespace std;

int main()
{
  Polynomial p1, p2, p3;
  
  cin >> p1 >> p2 >> p3;
  cout << "p1= " << p1;
  cout << "p2= " << p2;
  cout << "p3= " << p3;
  cout << endl;

   // Fase II
  SparsePolynomial sp1(p1), sp2(p2), sp3(p3);
  cout << "sp1= " << sp1;
  cout << "sp2= " << sp2;
  cout << "sp3= " << sp3;
  cout << endl;

  // Fase III
  double x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  cout << "p1(" << x1 << ")= " << p1.Eval(x1) << endl;
  cout << "p1(" << x2 << ")= " << p1.Eval(x2) << endl;
  cout << "p1(" << x3 << ")= " << p1.Eval(x3) << endl;
  cout << "p2(" << x1 << ")= " << p2.Eval(x1) << endl;
  cout << "p2(" << x2 << ")= " << p2.Eval(x2) << endl;
  cout << "p2(" << x3 << ")= " << p2.Eval(x3) << endl;
  cout << "p3(" << x1 << ")= " << p3.Eval(x1) << endl;
  cout << "p3(" << x2 << ")= " << p3.Eval(x2) << endl;
  cout << "p3(" << x3 << ")= " << p3.Eval(x3) << endl;
  cout << endl;

  cout << "sp1(" << x1 << ")= " << sp1.Eval(x1) << endl;
  cout << "sp1(" << x2 << ")= " << sp1.Eval(x2) << endl;
  cout << "sp1(" << x3 << ")= " << sp1.Eval(x3) << endl;
  cout << "sp2(" << x1 << ")= " << sp2.Eval(x1) << endl;
  cout << "sp2(" << x2 << ")= " << sp2.Eval(x2) << endl;
  cout << "sp2(" << x3 << ")= " << sp2.Eval(x3) << endl;
  cout << "sp3(" << x1 << ")= " << sp3.Eval(x1) << endl;
  cout << "sp3(" << x2 << ")= " << sp3.Eval(x2) << endl;
  cout << "sp3(" << x3 << ")= " << sp3.Eval(x3) << endl;
  cout << endl;

  // Fase IV
  cout << "p1 == p1? " << (p1.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p2 == p2? " << (p2.IsEqual(p2) ? "true" : "false") << endl;
  cout << "p3 == p3? " << (p3.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p1 == p2? " << (p1.IsEqual(p2) ? "true" : "false") << endl;
  cout << "p2 == p1? " << (p2.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p1 == p3? " << (p1.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p3 == p1? " << (p3.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p2 == p3? " << (p2.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p3 == p2? " << (p3.IsEqual(p2) ? "true" : "false") << endl;
  cout << endl;

  cout << "sp1 == sp1? " << (sp1.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp2 == sp2? " << (sp2.IsEqual(sp2) ? "true" : "false") << endl;
  cout << "sp3 == sp3? " << (sp3.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp1 == sp2? " << (sp1.IsEqual(sp2) ? "true" : "false") << endl;
  cout << "sp2 == sp1? " << (sp2.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp1 == sp3? " << (sp1.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp3 == sp1? " << (sp3.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp2 == sp3? " << (sp2.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp3 == sp2? " << (sp3.IsEqual(sp2) ? "true" : "false") << endl;
  cout << endl;

  cout << "sp1 == p1? " << (sp1.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp2 == p2? " << (sp2.IsEqual(p2) ? "true" : "false") << endl;
  cout << "sp3 == p3? " << (sp3.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp1 == p2? " << (sp1.IsEqual(p2) ? "true" : "false") << endl;
  cout << "sp2 == p1? " << (sp2.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp1 == p3? " << (sp1.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp3 == p1? " << (sp3.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp2 == p3? " << (sp2.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp3 == p2? " << (sp3.IsEqual(p2) ? "true" : "false") << endl;
  cout << endl;

/// Modificación Centro de Cálculo, Muestra los Extremos de sp1, sp2 y sp3.
cout << "Extremos de sp1: ";
sp1.ShowMinMax();

cout << "Extremos de sp2: ";
sp2.ShowMinMax();

cout << "Extremos de sp3: ";
sp3.ShowMinMax();

cout << endl;

  return 0;
}