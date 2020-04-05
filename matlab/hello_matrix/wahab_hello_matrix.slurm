#!/bin/bash
#
#SBATCH -N 1
#SBATCH -c 1
#SBATCH -J wahab_hello_matrix
#SBATCH -o %x.out%j
#
# A sample MATLAB job on Wahab

module load matlab/R2019b
#module list

matlab -nodisplay -nodesktop -r "hello_matrix, exit"
