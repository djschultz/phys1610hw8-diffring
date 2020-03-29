// 
// diffring_timestep.cc
//
// Time step module for 1d diffusion on a ring
//

#include "diffring_timestep.h"
#include <cblas.h>
#include <cmath>

// perform a single time step for the random walkers
void diffring_timestep(const rmatrix<double>& F, rvector<double>& P)
{
    int dim = F.extent(0);
    cblas_dgemv(CBLAS_ORDER::CblasRowMajor, CBLAS_TRANSPOSE::CblasNoTrans, dim, dim, 1.0, F.data(), dim, P, 1, 1.0, P, 1); // matrix vector muliplitcation F*P + P
    ////////////////////////////////////////////////
    //                                            //
    // IMPLEMENT THIS AS PART OF YOUR ASSIGNMENT! //
    //                                            //
    ////////////////////////////////////////////////
}

// fill the matrix needed in perform_time_step
void diffring_fill_timestep_matrix(rmatrix<double>& F, double D, double dt, double dx)
{   int dim = F.extent(0); // the dimension of our matrix
    double element = D*dt/dx/dx; // reduve the number of flops a bit by calculating this only once
    for(int i = 1; i < dim-1; i++){ // populate the diagonal and upper and lower diagonal except at the corners
	    F[i-1][i] = element; 
	    F[i][i] = -2*element;
	    F[i+1][i] = element;
    }
    F[dim-1][0] = element; // add boundary conditions
    F[0][0] = -2*element; // populate the diagonal at the corner
    F[1][0] = element; // populate teh lower diagonal at the corner
    F[dim-2][dim-1] = element; // populate the upper diagonal at the corner
    F[dim-1][dim-1] = -2*element; // populate the diagonal at the corner
    F[0][dim-1] = element; // add boundary conditions
    ////////////////////////////////////////////////
    //                                            //
    // IMPLEMENT THIS AS PART OF YOUR ASSIGNMENT! //
    //                                            //
    ////////////////////////////////////////////////
}
