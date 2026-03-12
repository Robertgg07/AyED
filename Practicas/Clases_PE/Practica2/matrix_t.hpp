/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file matrix_t.hpp
  * @author Robert García García alu0101825878
  * @date March 11 2026
  * @brief Clase matrix_t
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

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T> class matrix_t {

  public:
    matrix_t(const int = 0, const int = 0);
    ~matrix_t();
  
    void resize(const int, const int);
  
    // getters
    int get_m(void) const;
    int get_n(void) const;
  
    // getters-setters
    T& at(const int, const int);
    T& operator()(const int, const int);
  
    // getters constantes
    const T& at(const int, const int) const;
    const T& operator()(const int, const int) const;
  
    // operaciones y operadores
    void multiply(const matrix_t<T>&, const matrix_t<T>&);

    void write(ostream& = cout) const;
    void read(istream& = cin);

  private:
    int m_, n_; // m_ filas y n_ columnas
    vector_t<T> v_;
  
    int pos(const int, const int) const;
};

/// @brief Constructor de la clase matrix_t 
template<class T> matrix_t<T>::matrix_t(const int m, const int n) {

  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

/// @brief Destructor de la clase matrix_t
template<class T> matrix_t<T>::~matrix_t() {}

/// @brief Método para cambiar el tamaño de la matriz
template<class T> void matrix_t<T>::resize(const int m, const int n) {

  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

/// @brief Getter del número de filas
template<class T> inline int matrix_t<T>::get_m() const {

  return m_;
}

/// @brief Getter del número de columnas
template<class T> inline int matrix_t<T>::get_n() const {

  return n_;
}

/// @brief Método para obtener el elemento de la matriz en cierta posición
template<class T> T& matrix_t<T>::at(const int i, const int j) {

  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

/// @brief Sobrecarga del operator () para obtener el elemento de la matriz en cierta posición
template<class T> T& matrix_t<T>::operator()(const int i, const int j) {

  return at(i, j);
}

/// @brief Método constante para obtener el elemento de la matriz en cierta posición
template<class T> const T& matrix_t<T>::at(const int i, const int j) const {

  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

/// @brief Sobrecarga del operator () constante para obtener el elemento de la matriz en cierta posición
template<class T> const T& matrix_t<T>::operator()(const int i, const int j) const {

  return at(i, j);
}

/// @brief Método para poder escribir una matriz por pantalla
template<class T> void matrix_t<T>::write(ostream& os) const {

  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

/// @brief Método para poder leer una matriz por teclado
template<class T> void matrix_t<T>::read(istream& is) {

  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

/// @brief Método para obtener la posición en una matriz del elemento [i][j]
template<class T> inline int matrix_t<T>::pos(const int i, const int j) const {
  
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}

/// @brief Sobrecarga del operador >> para leer una matriz
template<class T> void operator>>(istream& is, matrix_t<T>& a) {

  a.read(is);
}

/// FASE III: producto matricial

/// @brief Método para multiplicar 2 matrices
template<class T> void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {

  assert(A.get_n() == B.get_m());

  resize (A.get_m(), B.get_n());

  for (int i{1}; i <= A.get_m(); i++) {

    for (int j{1}; j <= B.get_n(); j++) {

      at(i,j) = 0;

      for (int k{1}; k <= A.get_n(); k++) {

        at (i,j) = at(i,j) + A.at(i,k) * B.at(k,j); 
      }
    }
  }
}