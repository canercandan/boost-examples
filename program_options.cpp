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
