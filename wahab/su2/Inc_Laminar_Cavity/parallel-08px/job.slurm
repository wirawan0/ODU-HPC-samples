#!/bin/bash -l
#SBATCH -n 8
#SBATCH -N 1
#SBATCH -c 1
#SBATCH -J Inc_Laminar_Cavity_par8
#SBATCH -t 2:00:00
#SBATCH -o Inc_Laminar_Cavity_par8.out

# Source of input files:
# https://github.com/su2code/Tutorials/blob/master/incompressible_flow/Inc_Laminar_Cavity/lam_buoyancy_cavity.cfg

enable_lmod
module load container_env su2 slurm

echo "SU2 CFD simulation of incompressible laminar flow"
echo "Parallel job calculation: $SLURM_NTASKS tasks"
echo "SLURM_JOB_ID=${SLURM_JOB_ID:-Unknown}"
srun crun.su2 SU2_CFD lam_buoyancy_cavity.cfg


