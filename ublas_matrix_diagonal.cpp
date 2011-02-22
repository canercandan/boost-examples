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

#include <boost/numeric/ublas/banded.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

typedef double Indiv;
typedef ublas::matrix< Indiv > Matrix;
typedef ublas::diagonal_matrix< Indiv > DiagonalMatrix;

int main ()
{
    Matrix m (3, 3);

    for (unsigned i = 0; i < m.size1 (); ++ i)
	{
	    for (unsigned j = 0; j < m.size2 (); ++ j)
		{
		    m (i, j) = 3 * i + j;
		}
	}

    std::cout << m << std::endl;

    DiagonalMatrix dm (3);

    std::cout << dm << std::endl;

    ublas::banded_adaptor< Matrix > ba ( m, 1, 1 );

    std::cout << ba << std::endl;

    return 0;
}
