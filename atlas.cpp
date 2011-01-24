#include <boost/numeric/bindings/atlas/clapack.hpp>
#include <boost/numeric/bindings/traits/ublas_matrix.hpp>
#include <boost/numeric/bindings/traits/std_vector.hpp>

namespace ublas = boost::numeric::ublas;
namespace atlas = boost::numeric::bindings::atlas;

int main(void)
{
    std::size_t n = 5;
    ublas::matrix< double > A ( n, n );

    // fill matrix A

    std::vector< int > ipiv (n);
    atlas::lu_factor(A, ipiv);
    atlas::lu_invert(A, ipiv);

    return 0;
}
