//  libs/rank_list/example/median.cpp

//  Copyright (c) Universidad de Alcala 2007
//  Use, modification, and distribution is subject to the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See library home page at http://www.boost.org/libs/rank_list

/*
    Rank List "Median" example

    The code listed here uses the NPSV feature.
    See accompanying documentation for more details.

                                    February, 2007
                                    Martin Knoblauch Revuelta
                                    Universidad de Alcala (Spain)
                                    martin at aut.uah.es
*/

#include <iostream>
#include <time.h>
// NOTE: RANK LIST HAS BEEN
#include <boost/rank_list.hpp>      // PROPOSED AS A CANDIDATE
                                    // LIBRARY FOR ITS INCLUSION
using namespace std;                // IN BOOST. IT IS _NOT_ A
using namespace boost::rank_lists;  // BOOST LIBRARY. No yet.. ;-)

// PROGRAM BODY ---------------------------------------------------

int main ()
{
  typedef
      rank_list <int,                 // Samples will be of type int
      std::allocator<int>, // Same as default allocator
	unsigned>            // Width: number of occurences
  samples_container;              //        of a concrete value
  
samples_container A;            // A will store the samples
samples_container::iterator p;  // sorted by value. Repeated
// samples will be "compressed",
int sample, median;             // taking just one element per
int percentile, percentage;     // unique value. The NPSV width
unsigned total, seconds;        // will be the count of
time_t last, now;               // occurences. It allows viewing
bool found;                     // the sequence (indexing) as if
// the samples were all present.
  
 for (last=0, seconds=0; seconds<60; ) // Repeat during 1 minute:
     {
	 sample = rand ();                     // Get next sample
    
	 found = A.binary_search (sample, p);  // Search for it in the
	 // container
	 if (found)                                  // Already there?
	     A.npsv_set_width (p, A.npsv_width(p)+1);  //    count ++
	 else                                        // Not there?
	     A.insert (p, sample);                     //    count = 1

	 total = A.npsv_width ();
	 // Go to the middle (50%) of the
	 p = A.npsv_at_pos (total/2);  // Non Proportional Sequence
	 median = *p;                  // View (the median is there)
    
	 percentage = unsigned (rand()*100.0/(RAND_MAX+1)); // Now try
	 p = A.npsv_at_pos (total*percentage/100U);        // a percent
	 percentile = *p;                                 // chosen at
	 // random

	 now = time (NULL);
	 // Printing is slow, so
	 if (now!=last)                    // do it only once a second
	     {
		 cout << "total: " << total             // N. of samples
		      << "  unique: " << A.size ()      // N. of unique values
		      << "  median: " << median         // Current median
		      << "  percentile(" << percentage
		      << "%): " << percentile  // Current percentile
		      << endl;
		 last = now;
		 seconds ++;
	     }
     }

 getchar ();
 return 0;
}

