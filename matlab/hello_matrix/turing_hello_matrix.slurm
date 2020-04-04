#!/bin/bash -l
#
#SBATCH -N 1
#SBATCH -c 1
#SBATCH -J turing_hello_matrix
#SBATCH -o %x.out%j
#
# A sample MATLAB job on Turing

enable_lmod
module load matlab/2019
#module list

matlab -nodisplay -nodesktop -r "hello_matrix, exit"
