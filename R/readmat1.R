#!/usr/bin/Rscript --vanilla
#
# A demo program for reading in a matrix then printing it out
#

loadmatrix1 <- function(filename) {
    hdr <- read.table(filename, nrows=1,
                      col.names=c("magic", "numrows", "numcols"))
    if (toupper(hdr$magic) != "MATRIX") {
        stop(paste("Unrecognized format:", filename))
    }
    as.matrix(read.table(filename, skip=1, nrows=hdr$numrows))
}

printmatrix1 <- function(m) {
    write.table(format(m, justify="right"),
                row.names=F, col.names=F, quote=F)
}


args <- commandArgs(trailingOnly=TRUE)
if (length(args) < 1) {
    stop("Needs an input file name on arg1")
}

M <- loadmatrix1(args[1])
printmatrix1(M)

