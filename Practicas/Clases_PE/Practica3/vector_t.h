/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file vector_t.h
  * @author Robert García García alu0101825878
  * @date March 24 2026
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

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class vector_t {

  public:
  
    /// constructores
    vector_t(const int = 0);
    vector_t(const vector_t&); /// constructor de copia

    /// operador de asignación
    vector_t<T>& operator=(const vector_t<T>&);

    /// destructor
    ~vector_t();
  
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

    /// Redimensionado
    void resize(const int);
  
    /// E/S
    void read(std::istream& = std::cin);
    void write(std::ostream& = std::cout) const;

  private:

    T *v_;
    int sz_;
  
    void build(void);
    void destroy(void);
};

/// @brief Constructor de la clase vector_t
template<class T> vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) {

  build();
}

/// @brief Constructor de copia de la clase vector_t
template<class T> vector_t<T>::vector_t(const vector_t<T>& w) : v_(NULL), sz_(0) {

  *this = w; /// se invoca directamente al operator=
}

/// @brief Sobrecarga del operador = para asignación
template<class T> vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) {

  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  
  return *this;
}

/// @brief Destructor de la clase vector_t
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

/// @brief Método para cambiar el tamaño de un vector
template<class T> void vector_t<T>::resize(const int n) {

  destroy();
  sz_ = n;
  build();
}

/// @brief Getter del valor i del vector
template<class T> inline T vector_t<T>::get_val(const int i) const {
  
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/// @brief Getter del tamaño del vector
template<class T> inline int vector_t<T>::get_size() const {

  return sz_;
}

/// @brief Setter del valor i del vector
template<class T> void vector_t<T>::set_val(const int i, const T d) {

  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

/// @brief Método para devolver el valor i de un vector
template<class T> T& vector_t<T>::at(const int i) {

  assert(i >= 0 && i < get_size());
  return v_[i];
}

/// @brief Sobrecarga del operador [] para obtener el valor i de un vector
template<class T> T& vector_t<T>::operator[](const int i) {

  return at(i);
}

/// @brief Método para obtener el valor i de un vector
template<class T> const T& vector_t<T>::at(const int i) const {

  assert(i >= 0 && i < get_size());
  return v_[i];
}

/// @brief Sobrecarga del operador [] para obtener el valor i de un vector
template<class T> const T& vector_t<T>::operator[](const int i) const {

  return at(i);
}

/// @brief Método para leer un vector por teclado
template<class T> void vector_t<T>::read(std::istream& is) {

  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> at(i);
}

/// @brief Método para imprimir un vector por pantalla
template<class T> void vector_t<T>::write(std::ostream& os) const {

  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

/// @brief Sobrecarga del operador >> para leer un vector por teclado
template<class T> std::istream& operator>>(std::istream& is, vector_t<T>& v) {

  v.read(is);
  return is;
}

/// @brief Sobrecarga del operator << para imprimir un vector por pantalla
template<class T> std::ostream& operator<<(std::ostream& os, const vector_t<T>& v) {

  v.write(os);
  return os;
}

#endif  /// VECTORT_H_