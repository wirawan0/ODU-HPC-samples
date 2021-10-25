#!/bin/bash
#SBATCH -J hello-world-in-R
#SBATCH --mem 100G
#SBATCH --output hello_world2.out
#
# This job script is fancier:
# * output file is explicitly named
# * memory size is explicitly requested (100 GB for a node)

module load container_env R

crun Rscript hello_world.R

