#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/lambda/lambda.hpp>

using namespace boost::lambda;

int	main(void)
{
  std::vector<int>	v(10, 42);
  std::for_each(v.begin(), v.end(), std::cout << _1 << '\n');
  return 0;
}
