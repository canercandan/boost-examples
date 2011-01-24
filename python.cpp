#include <boost/python.hpp>

const char* greet()
{
  return "hello, world";
}

BOOST_PYTHON_MODULE(hello_ext)
{
  namespace bp = boost::python
  bp::def("greet", greet);
}
