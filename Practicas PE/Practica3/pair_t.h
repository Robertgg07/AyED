/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file pair_t.h
  * @author Robert García García alu0101825878
  * @date March 24 2026
  * @brief Clase pair_t.h
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

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {

  public:

    /// constructores
    pair_t(void); 
    pair_t(T, int);

    /// destructor
    ~pair_t(void);

    /// getters & setters
    T get_val(void) const;
    int get_inx(void) const;
    void set(T, int);

    /// E/S
    std::istream& read(std::istream& is = std::cin);
    std::ostream& write(std::ostream& os = std::cout) const;

  private:

    T val_;
    int inx_;
};

/// @brief Constructor por defecto de la clase pair_t
template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}

/// @brief Constructor de la clase pair_t
template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

/// @brief Destructor de la clase pair_t
template<class T> pair_t<T>::~pair_t() {}

/// @brief Setter del par
template<class T> void pair_t<T>::set(T val, int inx) {

  val_ = val;
  inx_ = inx;
}

/// @brief Getter del indice
template<class T> int pair_t<T>::get_inx() const {

  return inx_;
}

/// @brief Getter del valor
template<class T> T pair_t<T>::get_val() const {

  return val_;
}

/// @brief Método para leer un par por teclado
template<class T> std::istream& pair_t<T>::read(std::istream& is) {

  return is >> inx_ >> val_;
}

/// @brief Método para imprimir un par por pantalla
template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {

  return os << "(" << inx_ << ":" << val_ << ")";
}

/// @brief Sobrecarga del operador << para imprimir un par por pantalla
template<class T> std::ostream& operator<<(std::ostream& os, const pair_t<T>& p) {

  p.write(os);
  return os;
}

#endif  /// PAIRT_H_