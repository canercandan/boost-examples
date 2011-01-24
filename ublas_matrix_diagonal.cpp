#include <boost/numeric/ublas/banded.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

typedef double Indiv;
typedef ublas::matrix< Indiv > Matrix;
typedef ublas::diagonal_matrix< Indiv > DiagonalMatrix;

int main ()
{
    Matrix m (3, 3);

    for (unsigned i = 0; i < m.size1 (); ++ i)
	{
	    for (unsigned j = 0; j < m.size2 (); ++ j)
		{
		    m (i, j) = 3 * i + j;
		}
	}

    std::cout << m << std::endl;

    DiagonalMatrix dm (3);

    std::cout << dm << std::endl;

    ublas::banded_adaptor< Matrix > ba ( m, 1, 1 );

    std::cout << ba << std::endl;

    return 0;
}
