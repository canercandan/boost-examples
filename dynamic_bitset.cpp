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
#include <boost/dynamic_bitset.hpp>
#include <unistd.h>

int	main(void)
{
    unsigned long val = 256;

    boost::dynamic_bitset<>	x(9, val);

    std::cout << x << std::endl;

    // for (;x.to_ulong() < 256; x = x << 1)
    // 	{
    // 	    std::cout << x << std::endl;
    // 	    sleep(1);
    // 	}
}
