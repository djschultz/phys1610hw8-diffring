#!/bin/bash
#SBATCH --nodes=1
#SBATCH --cpus-per-task=16
#SBATCH --time=1:00:00
#SBATCH --job-name=diffring
#SBATCH --mail-type=FAIL

module load gcc rarray hdf5 netcdf boost

for i in {12..16}
do
    export OPENBLAS_NUM_THREADS=$i
    	(time ./diffring;)  2>> times.dat
    wait
done

