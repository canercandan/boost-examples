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
