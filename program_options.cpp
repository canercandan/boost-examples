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
#include <stdexcept>
#include <vector>
#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int	main(int ac, char** av)
{
  po::options_description	desc;
  po::variables_map		vm;

  try
    {
      desc.add_options()
	("help,h", "produce help message")
	("filename,f", po::value< std::vector<std::string> >()->composing(),
	 "provide a file")
	("verbose,v", po::value<int>()->default_value(0),
	 "set the verbose (cf. -v 0 = quiet)")
	("capitalize,c", po::value<bool>()->zero_tokens(), "capitalize mode")
	("email,e", po::value<std::string>()->multitoken(),
	 "email to send to")
	;

      po::store(po::parse_command_line(ac, av, desc), vm);
      po::notify(vm);

      if (vm.count("help"))
	{
	  std::cout << desc << std::endl;
	  exit(1);
	}
    }
  catch (std::exception& e)
    {
      std::stringstream ss;
      ss << "error: " << e.what();
      throw std::runtime_error(ss.str());
    }
  catch (...)
    {
      throw std::runtime_error("Exception of unknown type!");
    }

  std::vector< std::string >::const_iterator it, end;
  it = vm["filename"].as< std::vector< std::string > >().begin();
  end = vm["filename"].as< std::vector< std::string > >().end();
  for (; it != end; ++it)
    std::cout << *it << std::endl;
  return 0;
}
