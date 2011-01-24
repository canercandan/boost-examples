#include <map>
#include <string>

#include <boost/variant.hpp>

typedef std::map< boost::variant< int, std::string >, int >	MAP;

int	main(void)
{
  MAP	m;

  m["toto"] = 1;
  m[354235] = 1L;

  return 0;
}
