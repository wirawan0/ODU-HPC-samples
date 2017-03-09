#
# Makefile for sample codes
#

CXX = g++
CXXFLAGS = -g -O -Iinclude

LD = g++
LDFLAGS =

ALL_PROGS = mattest1.exe matread1.exe matmul1.exe

all: $(ALL_PROGS)

mattest1.exe: mattest1.o
	$(LD) $(LDFLAGS) $^ -o $@

matread1.exe: matread1.o
	$(LD) $(LDFLAGS) $^ -o $@

matmul1.exe: matmul1.o
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm *.exe *.o

