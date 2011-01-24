#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

int main(void)
{
    typedef double T;

    std::vector<T> ov(3);

    //vector<T> nv(ov);

    vector<T> v1(3);
    for (int i = 0, size = v1.size(), r = 3; i < size; v1(i) = r, ++i, --r);
    std::cout << v1 << std::endl;

    vector<T> v2(3);
    for (int i = 0, size = v2.size(), r = 10; i < size; v2(i) = r, ++i, ++r);
    std::cout << v2 << std::endl;

    vector<T> vrange = v2 - v1;

    std::cout << vrange << std::endl;

    T acc = 1;
    for (int i = 0, size = vrange.size(); i < size; acc *= vrange(i), ++i);
    std::cout << acc << std::endl;

    return 0;
}
