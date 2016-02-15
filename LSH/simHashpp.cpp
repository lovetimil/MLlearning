/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include <string>
extern "C"{
#include "simHash.h"
}
#include "simHashpp.h"

using std::string;

simHasher::simHasher(const string& str,int tokenSize){
	hash=simHash(str.c_str(),tokenSize);
}

int simHasher::hammingDist(const simHasher& other) const{
	return ::hammingDist(hash,other.getHash());
}

float simHasher::similarity(const simHasher& other) const{
	float fa=(float)hash;
	float fb=(float)other.getHash();
	if (fa>fb)
		return fb/fa;
	return fa/fb;
}

unsigned simHasher::getHash() const{
	return hash;
}

