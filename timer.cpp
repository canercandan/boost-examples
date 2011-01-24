#include <unistd.h>

#include <iostream>

#include <boost/timer.hpp>

int	main(void)
{
    boost::timer	tim;

    for (unsigned long i = 0; i < 1000000000; ++i);

    std::cout << tim.elapsed() << std::endl;

    return 0;
}
