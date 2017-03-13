# Sample job: Matrix multiplication

The first example of computational task is to multiply two matrices.
The same task is implemented in several popular languages:
C++, Python, and R.

Generally, a batch job consists of
(1) the _program_ to be launched on the compute node(s), as well as
(2) a _job script_.

A batch job takes no interaction from user while executing: All input
must be provided in the command-line argument of the program, or via
the input file.
Input files have become a common means to pass on the input to a batch job.
The output of a batch job is either printed to the job's output file
(usually recognized by an extension like `.o12345`, where `12345`
refers to the job number assigned by the job scheduler.

The _program_ may consist of one or more executable script files
(such as python `*.py` scripts or R `*.R` scipts), or
executable binary files (often bearing the `*.x` or `*.exe`
filename pattern).
In the case of compiled language such as C, C++, or Fortran, there
will be source files (e.g. `*.c`, `*.cpp`, or `*.f90`) to be compiled
into the binary executable program.

A _job script_ is essentially a shell script containing
special instructions to be passed to the job scheduler (SGE).
These are the lines prefixed by the `#$` character
located near the top of the script, before any commands.
This job script is what actually launches the _program_.


## C++

C++ codes need to be compiled before it can be executed.
A sample makefile has been provided, which provides the instructions
on how to build the executable programs.

Please go to `c++` directory and type `make` on the shell prompt.
Your session may look like (the shell prompt may look different):

    [user@turing ~/ODU-HPC-samples]$ cd c++
    [user@turing ~/ODU-HPC-samples/c++]$ make
    g++ -c mattest1.cpp -o mattest1.o -g -O -Iinclude
    g++  mattest1.o -o mattest1.exe
    g++ -c matread1.cpp -o matread1.o -g -O -Iinclude
    g++  matread1.o -o matread1.exe
    g++ -c matmul1.cpp -o matmul1.o -g -O -Iinclude
    g++  matmul1.o -o matmul1.exe

If there is no error, you successfully built all the sample executable
programs.

Now switch to `turing/c++` directory.
There is job script called `job-matmul1-c++-1x2.sge`.
Please take a look by using `cat` command:
p
    [user@turing ~/ODU-HPC-samples/c++]$ cd ../turing/c++
    [user@turing ~/ODU-HPC-samples/turing/c++]$ cat job-matmul1-c++-1x2.sge

Now submit this job to SGE:

    [user@turing ~/ODU-HPC-samples/c++]$ qsub job-matmul1-c++-1x2.sge

qsub will respond with an output like this (where the job number will
be different):

    Your job 251245 ("Matmul-1x2") has been submitted

You can check the job progress by invoking:

    [user@turing ~/ODU-HPC-samples/c++]$ qstat -u $USER

Here, `$USER` is a shell variable containing your user name on Turing.
When this job is executed, there wil be an output file in this
subdirectory named `Matmul-1x2.o251245`.
This file name is formatted as `<JOBNAME>.o<JOBNUMBER>`.
Inspect the content of that file, which should be like this:

    [user@turing ~/ODU-HPC/samples/c++]$ cat Matmul-1x2.o251245
    ## matmul1 ## infile1=../../samples/matrices/matrix01.in infile2=../../samples/matrices/matrix02.in
    A dimensions = 4 5
    B dimensions = 5 3
    -6393.28 5491.5 -3923.1
    -2279.63 2019.51 -2163.88
    -366.494 -137.821 -1151.42
    904.896 -2839.5 1344.5


## Python

Python is an interpreted language, therefore it does not need to be compiled.
To launch a python script `foo.py`, you can simply invoke:

    [use@turing ~/some-dir]$ python foo.py [ARGUMENTS]

The example job script for python is provided in `turing/python` subdirectory.
In that directory, examine the content of `job-matmul1-python-1x2.sge`.
The script itself is provided in `python` subdirectory, just below the
root directory of the package.

*Exercise:* Submit that python job script using the usual `qsub` command:

    [user@turing ~/ODU-HPC-samples/turing/python]$ cat job-matmul1-python-1x2.sge

This script performas the same matrix multiplication of two input
matrices as the C++ example; therefore the resulting matrix should be
identical to the previous (C++) calculation.

*Exercise:* Examine the output after the job is completed.

Make sure that there is no glaring python and C++
output.  If there is a difference, what looks different? Why?


## R

There is also the same example, implemented in R scripting language.
Please inspect `R` and `turing/R` subdirectories for the R program
and its job script.
