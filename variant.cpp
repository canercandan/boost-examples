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

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <boost/lambda/lambda.hpp>
#include <boost/variant.hpp>

typedef boost::variant< unsigned int, double, std::string >	Variant;

using namespace boost::lambda;

int	main(void)
{
  double	dd = 12.2;
  unsigned int	lambda = 42;
  std::string	string = "hello world!";

  Variant	v_dd = dd;
  Variant	v_lambda = lambda;
  Variant	v_string = string;

  std::cout << v_dd << std::endl;
  std::cout << v_lambda << std::endl;
  std::cout << v_string << std::endl;

  std::vector< Variant >	vec;
  vec.push_back(dd);
  vec.push_back(lambda);
  vec.push_back(string);

  std::for_each(vec.begin(), vec.end(), std::cout << _1 << '\n');

  return 0;
}
