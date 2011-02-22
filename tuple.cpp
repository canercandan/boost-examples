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

#include <iostream>
//#include <boost/tuple/tuple.hpp> // already included by tuple_io.hpp
#include <boost/tuple/tuple_io.hpp>

using boost::tuples::tuple;
using boost::tuples::make_tuple;
using boost::tuples::set_open;
using boost::tuples::set_close;
using boost::tuples::set_delimiter;

tuple<std::string, double, int>	get_tuples()
{
  return make_tuple("coucou", 5.5, 42);
}

int	main(void)
{
  tuple<int, int>	tt(1, 2);

  std::cout << tt << std::endl;
  //std::cout << tt.get<0>() << std::endl;
  //std::cout << tt.get<1>() << std::endl;

  tt.get<0>() = 42;
  tt.get<1>() = 24;

  std::cout << set_open('[') << set_close(']') << set_delimiter(',') << tt << std::endl;

  std::cout << get_tuples() << std::endl;

  return 0;
}
