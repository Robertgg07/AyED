/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file rational_t.cpp
  * @author Robert García García alu0101825878
  * @date March 11 2026
  * @brief Implementación de la clase rational_t
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

#include "rational_t.hpp"

/// @brief Constructor de la clase rational_t 
rational_t::rational_t(const int n, const int d) {

  assert(d != 0);
  num_ = n, den_ = d;
}

/// @brief Getter del numerador
inline int rational_t::get_num() const {

  return num_;
}

/// @brief Getter del denominador
inline int rational_t::get_den() const {

  return den_;
}

/// @brief Setter del numerador
void rational_t::set_num(const int n) {

  num_ = n;
}

/// @brief Setter del denominador
void rational_t::set_den(const int d) {

  assert(d != 0);
  den_ = d;
}

/// @brief Método que calcula el racional
inline double rational_t::value() const {

  return double(get_num()) / get_den();
}

/// @brief Método que calcula el opuesto de un racional
rational_t rational_t::opposite() const {

  return rational_t((-1) * get_num(), get_den());
}

/// @brief Método que calcula el reciproco de un racional
rational_t rational_t::reciprocal() const {

  return rational_t(get_den(), get_num());
}

/// @brief Método que compara si un racional es igual a otro teniendo en cuenta precision como error
bool rational_t::is_equal(const rational_t& r, const double precision) const {

  return fabs(value() - r.value()) < precision;
}

/// @brief Método que compara si un racional es mayor a otro teniendo en cuenta precision como error
bool rational_t::is_greater(const rational_t& r, const double precision) const {

  return (value() - r.value()) > precision;
}

/// @brief Método que compara si un racional es menor a otro teniendo en cuenta precision como error
bool rational_t::is_less(const rational_t& r, const double precision) const {

  return r.is_greater(*this, precision);
}

/// @brief Método que suma 2 racionales
rational_t rational_t::add(const rational_t& r) const {

  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), get_den() * r.get_den());
}

/// @brief Método que resta 2 racionales
rational_t rational_t::substract(const rational_t& r) const {

  return add(r.opposite());
}

/// @brief Método que multiplica 2 racionales
rational_t rational_t::multiply(const rational_t& r) const {

  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}

/// @brief Método que divide 2 racionales
rational_t rational_t::divide(const rational_t& r) const {

  return multiply(r.reciprocal());
}

/// @brief Sobrecarga del operador + para hacer la suma de dos racionales
rational_t operator+(const rational_t& a, const rational_t& b) {

  return a.add(b);
}

/// @brief Sobrecarga del operador - para hacer la resta de dos racionales
rational_t operator-(const rational_t& a, const rational_t& b) {

  return a.substract(b);
}

/// @brief Sobrecarga del operador * para hacer la multiplicación de dos racionales
rational_t operator*(const rational_t& a, const rational_t& b) {

  return a.multiply(b);
}

/// @brief Sobrecarga del operador / para hacer la división de dos racionales
rational_t operator/(const rational_t& a, const rational_t& b) {

  return a.divide(b);
}

/// @brief Método para mostrar un racional por pantalla
void rational_t::write(ostream& os) const {

  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

/// @brief Método para leer un racional por el teclado
void rational_t::read(istream& is) {

  is >> num_ >> den_;
  assert(den_ != 0);
}

/// @brief Sobrecarga del operador << para poder imprimir un racional
ostream& operator<<(ostream& os, const rational_t& r) {

  r.write(os);
  return os;
}

/// @brief Sobrecarga del operador >> para poder leer un racional por teclado
istream& operator>>(istream& is, rational_t& r) {

  r.read(is);
  return is;
}