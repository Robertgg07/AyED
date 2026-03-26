/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file sparse_vector_t.h
  * @author Robert García García alu0101825878
  * @date March 24 2026
  * @brief Clase sparse_vector_t.h
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

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  /// fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

class sparse_vector_t {

  public:

    /// constructores
    sparse_vector_t(const int = 0);
    sparse_vector_t(const vector_t<double>&, const double = EPS); /// constructor normal
    sparse_vector_t(const sparse_vector_t&);  /// constructor de copia

    /// operador de asignación
    sparse_vector_t& operator=(const sparse_vector_t&);

    /// destructor
    ~sparse_vector_t();
  
    /// getters
    int get_nz(void) const;
    int get_n(void) const;

    /// getters-setters
    pair_double_t& at(const int);
    pair_double_t& operator[](const int);
  
    /// getters constantes
    const pair_double_t& at(const int) const;
    const pair_double_t& operator[](const int) const;

    /// E/S
    void write(std::ostream& = std::cout) const;

  private:

    pair_vector_t pv_;  /// valores + índices
    int nz_;            /// nº de valores distintos de cero = tamaño del vector
    int n_;             /// tamaño del vector original

    /// bool IsNotZero(const double, const double = EPS) const;
};

/// @brief Método para comprobar si un valor no es cero
bool IsNotZero(const double val, const double eps = EPS) {

  return fabs(val) > eps;
}

/// @brief Constructor por defecto de la clase sparse_vector_t
sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

/// FASE II
/// @brief Constructor de la clase sparse_vector_t
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps) : pv_(), nz_(0), n_(0) {

  /// poner el código aquí (en principio este esta bien pero no se si es muy eficiente)
  n_ = v.get_size();

  for (int i{}; i < v.get_size(); i++) {

    if (IsNotZero(v.at(i))) {

      nz_ ++;
    }
  }

  pv_.resize(nz_);

  int indice_actual{};

  for (int i{}; i < v.get_size(); i++) {

    if (IsNotZero(v.at(i),eps)) {

      pv_.at(indice_actual).set(v.at(i),i);
      indice_actual++;
    }
  }
}

/// @brief Constructor de copia de la clase sparse_vector_t
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {

  *this = w;  /// se invoca directamente al operator=
}

/// @brief Sobrecarga del operador = para asignación
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {

  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}

/// @brief Destructor de la clase sparse_vector_t
sparse_vector_t::~sparse_vector_t() {}

/// @brief Getter del tamaño del vector disperso
inline int sparse_vector_t::get_nz() const {

  return nz_;
}

/// @brief Getter del tamaño del vector original
inline int sparse_vector_t::get_n() const {

  return n_;
}

/// @brief Método para obtener el valor i de un vector
pair_double_t& sparse_vector_t::at(const int i) {

  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/// @brief Sobrecarga del operador[] para obtener el valor i de un vector
pair_double_t& sparse_vector_t::operator[](const int i) {

  return at(i);
}

/// @brief Método para obtener el valor i de un vector
const pair_double_t& sparse_vector_t::at(const int i) const {

  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/// @brief Sobrecarga del operador[] para obtener el valor i de un vector
const pair_double_t& sparse_vector_t::operator[](const int i) const {

  return at(i);
}

/// @brief Método para imprimir un vector por pantalla
void sparse_vector_t::write(std::ostream& os) const { 

  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

/// @brief Sobrecarga del operador << para imprimir un vector por pantalla
std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {

  sv.write(os);
  return os;
}

#endif  /// SPARSE_VECTORT_H_