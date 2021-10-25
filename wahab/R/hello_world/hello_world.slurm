#!/bin/bash
#SBATCH -J hello-world-in-R

module load container_env R

crun Rscript hello_world.R

