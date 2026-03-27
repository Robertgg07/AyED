/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file polynomial.h
  * @author Robert García García alu0101825878
  * @date March 24 2026
  * @brief Clase polynomial
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

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  /// fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

/// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {

  public:
    /// constructores
    Polynomial(const int n = 0) : vector_t<double>(n) {};
    Polynomial(const Polynomial& pol) : vector_t<double>(pol) {}; /// constructor de copia

    /// destructor
    ~Polynomial() {};

    /// E/S
    void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
    /// operaciones
    double Eval(const double) const;
    bool IsEqual(const Polynomial&, const double = EPS) const;
 };

/// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {

  public:
  
    /// constructores
    SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
    SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
    SparsePolynomial(const SparsePolynomial&);  /// constructor de copia

    /// destructor
    ~SparsePolynomial() {};

    /// E/S
    void Write(std::ostream& = std::cout) const;
  
    /// operaciones
    double Eval(const double) const;
    bool IsEqual(const SparsePolynomial&, const double = EPS) const;
    bool IsEqual(const Polynomial&, const double = EPS) const;

    /// @brief Modificación centro de Cálculo, Método ShowMinMax
    void ShowMinMax(std::ostream& os = std::cout) const;
};

/// @brief Método para imprimir un polinomio por vector denso
void Polynomial::Write(std::ostream& os, const double eps) const {

  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

/// @brief Sobrecarga del operador << para imprimir un polinomio de vector denso 
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {

  p.Write(os);
  return os;
}

/// Operaciones con polinomios

/// FASE III
/// @brief Evaluación de un polinomio representado por vector denso
double Polynomial::Eval(const double x) const {

  double result{0.0};

  for (int i{}; i < get_size(); i++) {

    result = result + at(i) * pow(x,i);
  }

  return result;
}

/// FASE IV
/// @brief Comparación si son iguales dos polinomios representados por vectores densos
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {

  bool differents = false;

  for (int i{}; (i < get_size()) && (i < pol.get_size()) && (!differents); i++) {

    if (abs(at(i) - pol.at(i)) > eps) {

      differents = true;
    }
  }

  if (get_size() < pol.get_size()) {

    for (int i{get_size()}; (i < pol.get_size()) && (!differents); i++) {

      if (abs(pol.at(i)) > eps) {

      differents = true;
      
      }
    }
  }

  if (get_size() > pol.get_size()) {

    for (int i{pol.get_size()}; (i < get_size()) && (!differents); i++) {

      if (abs(at(i)) > eps) {

      differents = true;
      
      }
    }
  }

  return !differents;
}

/// @brief Constructor de copia de SparsePolynomial
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {

  *this = spol;   /// se invoca directamente al operator=
}

/// @brief Método para imprimir un polinomio con vector disperso
void SparsePolynomial::Write(std::ostream& os) const {

  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

/// @brief Sobrecarga del operador << para imprimir un polinomio con vector disperso 
std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {

  p.Write(os);
  return os;
}

/// Operaciones con polinomios

/// FASE III
/// @brief Evaluación de un polinomio representado por vector disperso
double SparsePolynomial::Eval(const double x) const {

  double result{0.0};

  for (int i{}; i < get_nz(); i++) {

    result = result + at(i).get_val() * pow(x,at(i).get_inx());
  }

  return result;
}

/// FASE IV
/// @brief Compara si dos polinomios representados por vectores dispersos son iguales 
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const {

  bool differents = false;

  if (get_nz() != spol.get_nz()) {

    return false;
  }

  for (int i{}; (i < get_nz()) && (!differents); i++) {

    if (abs((at(i).get_val()) - (spol.at(i).get_val())) > eps) {

      differents = true;
    }
  }
  return !differents;
}

/// @brief Compara si dos polinomios representados por vector disperso y vector denso son iguales
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {

  bool differents = false;
  
  int min_size{};

  if (get_n() < pol.get_size()) {

    min_size = get_n();
  } else {

    min_size = pol.get_size();
  }

  for (int i{}; (i < min_size) && (!differents); i++ ) {

    bool index_found{false};

    for (int j{}; (j < get_nz()) && (!differents) && (!index_found); j++) {

      if (at(j).get_inx() == i) {

        index_found = true;
        if (abs(at(j).get_val() - pol.at(i)) > eps) {

          differents = true;
        }
      }
    }

    if (!index_found && abs(pol.at(i)) > eps) {

      differents = true;
    }
  }

  if (get_n() < pol.get_size()) {

    for (int i{min_size}; (i < pol.get_size()) && (!differents); i++) {

      if (abs(pol.at(i)) > eps) {
        
        differents = true;
      } 
    }
  }

  if (get_n() > pol.get_size()) {

    for (int i{}; (i < get_nz()) && (!differents); i++) {

      if (at(i).get_inx() >= min_size && abs(at(i).get_val()) > eps) {
        
        differents = true;
      } 
    }
  }

  return !differents;
}

/// @brief Modificación Centro de Cálculo, Cálcula el valor del monómio de grado mayor y menor.
/// @brief Mostrar monomio de menor y mayor grado (no nulos) recorriendo el vector
void SparsePolynomial::ShowMinMax(std::ostream& os) const {

  if (get_nz() == 0) {
    os << "Polinomio nulo" << std::endl;
    return;
  }

  //Se inicializa en 0 
  pair_double_t min = at(0);
  pair_double_t max = at(0);

  for (int i{1}; i < get_nz(); i++) {

    if (at(i).get_inx() < min.get_inx()) {
      min = at(i);
    }

    if (at(i).get_inx() > max.get_inx()) {
      max = at(i);
    }
  }

  // Imprimir el menor grado
  os << "Menor grado: " << min.get_val();
  if (min.get_inx() > 0) {
    os << " x";
    if (min.get_inx() > 1)
      os << "^" << min.get_inx();
  }

  // Imprimir el mayor grado
  os << " | Mayor grado: " << max.get_val();
  if (max.get_inx() > 0) {
    os << " x";
    if (max.get_inx() > 1)
      os << "^" << max.get_inx();
  }

  os << std::endl;
}
#endif  /// POLYNOMIAL_H_