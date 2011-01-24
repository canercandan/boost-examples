#include <iostream>
#include <boost/logic/tribool.hpp>

using namespace boost::logic;

int	main(void)
{
  tribool	b(indeterminate);

  if (indeterminate(b))
    std::cout << "coco" << std::endl;

  if (b == true)
    std::cout << "true" << std::endl;
  else if (b == false)
    std::cout << "false" << std::endl;
  else
    std::cout << "unknown" << std::endl;
}
