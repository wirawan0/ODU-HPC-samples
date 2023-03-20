# -*- R *-*
#
# Demo script to calculate Pi
# This is basically an R reimplementation of pi.py
# found in the old HPC Carpentry's hpc-intro lesson
# (now should be spun of as an independent lesson).

inside_circle <- function(total_count) {
    x <- runif(total_count)
    y <- runif(total_count)
    r <- sqrt(x^2 + y^2)
    return(sum(r <= 1))
}


calc_pi <- function() {
    # Main routine to calculate Pi
    argv <- commandArgs(trailingOnly <- TRUE)
    total_count <- as.integer(argv[1])
    print(total_count)
    pi_est <- inside_circle(total_count) / total_count * 4
    print(pi_est)
}

calc_pi()
