/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file vector_t.hpp
  * @author Robert García García alu0101825878
  * @date March 11 2026
  * @brief Clase vector_t
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

#include "rational_t.hpp"

using namespace std;

template<class T> class vector_t {

  public:

    vector_t(const int = 0);
    ~vector_t();
  
    void resize(const int);
  
    /// getters
    T get_val(const int) const;
    int get_size(void) const;
  
    /// setters
    void set_val(const int, const T);
  
    /// getters-setters
    T& at(const int);
    T& operator[](const int);
  
    /// getters constantes
    const T& at(const int) const;
    const T& operator[](const int) const;

    void write(ostream& = cout) const;
    void read(istream& = cin);
    void sum(const vector_t<T>&, const vector_t<T>&);
  private:

    T *v_;
    int sz_;
  
    void build(void);
    void destroy(void);
};

/// @brief Constructor clase vector_t 
template<class T> vector_t<T>::vector_t(const int n) { 
  
  sz_ = n;
  build();
}

/// @brief Destructor clase vector_t
template<class T> vector_t<T>::~vector_t() {

  destroy();
}

/// @brief Método para construir un vector
template<class T> void vector_t<T>::build() {

  v_ = NULL;

  if (sz_ != 0) {

    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

/// @brief Método para destruir un vector 
template<class T> void vector_t<T>::destroy() {

  if (v_ != NULL) {

    delete[] v_;
    v_ = NULL;
  }

  sz_ = 0;
}

/// @brief Método que cambia el tamaño de un vector 
template<class T> void vector_t<T>::resize(const int n) {

  destroy();
  sz_ = n;
  build();
}

/// @brief Getter de un valor del vector
template<class T> inline T vector_t<T>::get_val(const int i) const {

  assert(i >= 0 && i < get_size());
  return v_[i];
}

/// @brief Getter del tamaño del vector
template<class T> inline int vector_t<T>::get_size() const {

  return sz_;
}

/// @brief Seter de un valor del vector
template<class T> void vector_t<T>::set_val(const int i, const T d) {

  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

/// @brief Getter de un valor del vector
template<class T> T& vector_t<T>::at(const int i) {

  assert(i >= 0 && i < get_size());
  return v_[i];
}

/// @brief Sobrecarga del operador [] para obtener un valor de un vector
template<class T> T& vector_t<T>::operator[](const int i) {

  return at(i);
}

/// @brief Getter de un valor del vector
template<class T> const T& vector_t<T>::at(const int i) const {

  assert(i >= 0 && i < get_size());
  return v_[i];
}

/// @brief Sobrecarga del operador [] para obtener un valor de un vector
template<class T> const T& vector_t<T>::operator[](const int i) const {

  return at(i);
}

/// @brief Método para poder imprimir un vector
template<class T> void vector_t<T>::write(ostream& os) const {

  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}

/// @brief Método para poder leer un vector
template<class T> void vector_t<T>::read(istream& is) {

  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}

/// FASE II: producto escalar

/// @brief Método que calcula el producto escalar de dos vectores
template<class T> T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {

  assert(v.get_size() == w.get_size());

  T producto_escalar{};

  for (int i{}; i < v.get_size(); i++) {

    producto_escalar = producto_escalar + v.at(i) * w.at(i);
  }

  return producto_escalar;
}

/// @brief Método que calcula el producto escalar de dos vectores
double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  
  assert(v.get_size() == w.get_size());

  double producto_escalar{};

  for (int i{}; i < v.get_size(); i++) {

    producto_escalar = producto_escalar + v.at(i).value() * w.at(i).value();
  }

  return producto_escalar;
}

/// @brief Método que suma dos vectores
/// Modificación Centro de Cálculo

template<class T> void vector_t<T>::sum(const vector_t<T>& A, const vector_t<T>& B) {

  assert(A.get_size() == B.get_size());

  resize(A.get_size());

  for (int i{}; i < get_size(); i++) {

    at(i) = A.at(i) + B.at(i);
  }
}