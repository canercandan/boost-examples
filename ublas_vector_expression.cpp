#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

int main () {
  using namespace boost::numeric::ublas;
  vector<std::complex<double> > v (3);
  for (unsigned i = 0; i < v.size (); ++ i)
    v (i) = std::complex<double> (i, i+4);

  std::cout << "original: " << v << std::endl;
  std::cout << "negation: " << - v << std::endl;
  std::cout << "conj: " << conj (v) << std::endl;
  std::cout << "real: " << real (v) << std::endl;
  std::cout << "imag: " << imag (v) << std::endl;
  std::cout << "trans: " << trans (v) << std::endl;
  std::cout << "herm: " << herm (v) << std::endl;
  std::cout << "square: " << v * std::complex<double>(2) << std::endl;
}
