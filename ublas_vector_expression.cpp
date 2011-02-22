// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 * Caner Candan <caner@candan.fr>, http://caner.candan.fr
 */

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

int main () {
  using namespace boost::numeric::ublas;
  vector<std::complex<double> > v (3);
  for (unsigned i = 0; i < v.size (); ++ i)
    v (i) = std::complex<double> (i, i+4);

  std::cout << "original: " << v << std::endl;
  std::cout << "negation: " << - v << std::endl;
  std::cout << "conj: " << conj (v) << std::endl;
  std::cout << "real: " << real (v) << std::endl;
  std::cout << "imag: " << imag (v) << std::endl;
  std::cout << "trans: " << trans (v) << std::endl;
  std::cout << "herm: " << herm (v) << std::endl;
  std::cout << "square: " << v * std::complex<double>(2) << std::endl;
}
