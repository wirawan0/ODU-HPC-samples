#!/bin/bash -l
#SBATCH -n 1
#SBATCH -c 1
#SBATCH -J Inc_Laminar_Cavity
#SBATCH -t 2:00:00
#SBATCH -o Inc_Laminar_Cavity.out

enable_lmod
module load container_env su2 slurm

srun crun.su2 SU2_CFD lam_buoyancy_cavity.cfg


