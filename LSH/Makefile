# Makefile for LSH

CXX=g++
CXXFLAGS=-Wall -O2

CC=gcc
CCFLAGS=-Wall -O2

targets=simHash.o simHashpp.o

.PHONY:
	clean all

all:test
test:${targets} testSimHash.o
	${CXX} ${targets} testSimHash.o -o test
	strip test

%.o:%.cpp
	${CXX} -c ${CXXFLAGS} $< -o $@

%.o:%.c
	${CC} -c ${CCFLAGS} $< -o $@

clean:
	rm -f ${targets} testSimHash.o test

simHash.o:simHash.h
simHashpp.o:simHash.h simHashpp.h
testSimHash.o:simHashpp.h
