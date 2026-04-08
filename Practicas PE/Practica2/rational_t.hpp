/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos 2025-2026
  *
  * @file rational_t.hpp
  * @author Robert García García alu0101825878
  * @date March 11 2026
  * @brief Declaración de la clase rational_t
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
#include <cmath>
# define EPSILON 1e-6

using namespace std;

class rational_t {

  public:
    rational_t(const int = 0, const int = 1);
    ~rational_t() {}
  
    /// getters
    int get_num() const;
    int get_den() const;
  
    /// setters
    void set_num(const int);
    void set_den(const int);

    double value(void) const;
    rational_t opposite(void) const;
    rational_t reciprocal(void) const;

    bool is_equal(const rational_t&, const double precision = EPSILON) const;
    bool is_greater(const rational_t&, const double precision = EPSILON) const;
    bool is_less(const rational_t&, const double precision = EPSILON) const;

    rational_t add(const rational_t&) const;
    rational_t substract(const rational_t&) const;
    rational_t multiply(const rational_t&) const;
    rational_t divide(const rational_t&) const;

    void write(ostream& os = cout) const;
    void read(istream& is = cin);
  
  private:
    int num_, den_;
};

/// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

/// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);