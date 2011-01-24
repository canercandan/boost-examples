#include <iostream>
#include <boost/dynamic_bitset.hpp>
#include <unistd.h>

int	main(void)
{
    unsigned long val = 256;

    boost::dynamic_bitset<>	x(9, val);

    std::cout << x << std::endl;

    // for (;x.to_ulong() < 256; x = x << 1)
    // 	{
    // 	    std::cout << x << std::endl;
    // 	    sleep(1);
    // 	}
}
