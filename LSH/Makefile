# Makefile for LSH

CXX=g++
CXXFLAGS+=-Wall -O2 -std=c++11

CC=gcc
CCFLAGS+=-Wall -O2

targets=simHash.o simHashpp.o hamMap.o

.PHONY:
	clean all test

all:test
test:testSimHash testHamMap

testSimHash:${targets} testSimHash.o
	${CXX} ${CXXFLAGS} ${targets} testSimHash.o -o testSimHash

testHamMap:${targets} testHamMap.o
	${CXX} ${CXXFLAGS} ${targets} testHamMap.o -o testHamMap

%.o:%.cpp
	${CXX} -c ${CXXFLAGS} $< -o $@

%.o:%.c
	${CC} -c ${CCFLAGS} $< -o $@

clean:
	rm -f ${targets} testSimHash.o testHamMap.o testSimHash testHamMap

simHash.o:simHash.h
simHashpp.o:simHash.h simHashpp.h
testSimHash.o:simHashpp.h
hamMap.o:simHash.h
