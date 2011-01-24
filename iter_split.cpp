#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

int	main(void)
{
  std::string	str("Hello->PASPAS->TOTO");
  std::vector<std::string>	vec;

  boost::iter_split(vec, str, boost::first_finder("->"));
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;

  return 0;
}
