// 
// walkring_timestep.cc
//
// Time stepping module for 1d random walk on a ring
//

#include "walkring_timestep.h"
#include <random>
#include <iostream>
// Perform a single time step for the random walkers
//
// parameters:
//
//  walkerpositions: the positions of a number of walkers (note that
//                   the number of walker Z can be found from
//                   Z=walkerpositions.size())
//
//  N:               the number of possible positions. All positions
//                   in the walkerpositions array should remain
//                   between 0 and N-1
//
//  prob:            the probability to jump to the left. Also the
//                   probability to just right.  (the probability to
//                   stay on the same spot is thus 1-2p.)
//
// output:
//
//  the content of the walkerpositions arrays should have changed to
//  reflect the random movement of all walker (i.e., they will each
//  have been given a chance to move on position to the left or two
//  the right).
//
void walkring_timestep(rvector<int>& walkerpositions, int N, double prob)
{   double r = 0.0; // initialize variable which will be our random number
    for(int i = 0; i < walkerpositions.extent(0); i++){ //loop over all walkers
        r = ((double) rand() / (RAND_MAX)); // calculate a random number between 0 and 1
        if(r < prob){ // move to the right if r \in (0,prob)
            walkerpositions[i] = (walkerpositions[i] + 1) % N; // modulo N so that we don't exceed N
	}else if(r > 1.0-prob){ // move to the left if r \in (1-prob,prob)
	    walkerpositions[i] = (walkerpositions[i] + N- 1) % N; // add N-1 modulo N so that we don't go negative
	}else{ // don't move at all
	    walkerpositions[i] = walkerpositions[i];
	}
    }
    ////////////////////////////////////////////////
    //                                            //
    // IMPLEMENT THIS AS PART OF YOUR ASSIGNMENT! //
    //                                            //
    ////////////////////////////////////////////////
}


