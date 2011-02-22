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

using namespace boost::numeric::ublas;

int main(void)
{
    typedef double T;

    std::vector<T> ov(3);

    //vector<T> nv(ov);

    vector<T> v1(3);
    for (int i = 0, size = v1.size(), r = 3; i < size; v1(i) = r, ++i, --r);
    std::cout << v1 << std::endl;

    vector<T> v2(3);
    for (int i = 0, size = v2.size(), r = 10; i < size; v2(i) = r, ++i, ++r);
    std::cout << v2 << std::endl;

    vector<T> vrange = v2 - v1;

    std::cout << vrange << std::endl;

    T acc = 1;
    for (int i = 0, size = vrange.size(); i < size; acc *= vrange(i), ++i);
    std::cout << acc << std::endl;

    return 0;
}
