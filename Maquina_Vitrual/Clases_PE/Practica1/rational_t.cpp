/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file rational_t.cpp
  * @author Robert García García
  * @date Feb 20 2026
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

/// @brief Constructor de la clase racional_t
rational_t::rational_t(const int n, const int d) {

  assert(d != 0);
  num_ = n, den_ = d;
}

/// @brief El getter, devuelve el numerador
int rational_t::get_num() const {

  return num_;
}

/// @brief EL getter, devuelve el denominador
int rational_t::get_den() const {

  return den_;
}

/// @brief El setter del numerador
void rational_t::set_num(const int n) {

  num_ = n;
}

/// @brief El setter del denominador
void rational_t::set_den(const int d) {

  assert(d != 0);
  den_ = d;
}

/// @brief Métod: devolver el número racional en forma decimal
double rational_t::value() const {

  return double(get_num()) / get_den();
}

/// @brief Método: compara si un racional es igual a otro 
bool rational_t::is_equal(const rational_t& r, const double precision) const {

  return (fabs(value() - r.value()) < precision);
}

/// @brief Método: compara si un racional es mayor a otro 
bool rational_t::is_greater(const rational_t& r, const double precision) const {

  return ((value() - r.value()) > precision);
}

/// @brief Método: compara si un racional es menor a otro
bool rational_t::is_less(const rational_t& r, const double precision) const {

  return ((r.value() - value()) > precision);
}

/// @brief Método: compara si un racional es igual a otro 
bool rational_t::is_equalzero( const double precision) const {

  return (fabs(value() < precision));
}

/// @brief Método: suma 2 racionales
rational_t rational_t::add(const rational_t& r) {

  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), get_den() * r.get_den());
}

/// @brief Método: resta 2 racionales
rational_t rational_t::substract(const rational_t& r) {

  return rational_t(get_num() * r.get_den() + get_den() * r.get_num() * (-1), get_den() * r.get_den());
}

/// @brief Método: multiplica 2 racionales
rational_t rational_t::multiply(const rational_t& r) {

  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}

/// @brief Método: divide 2 racionales
rational_t rational_t::divide(const rational_t& r) {

  return rational_t(get_num() * r.get_den(), get_den() * r.get_num());
}

/// @brief Método para mostrar un racional
void rational_t::write(ostream& os) const {

  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

/// @brief Método que lee un racional del teclado
void rational_t::read(istream& is) {

  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}

/// @brief Método: Hallar un racional al cuadrado
rational_t rational_t::cuadrado() {

  return rational_t(get_num() * get_num(), get_den() * get_den());
}