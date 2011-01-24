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
