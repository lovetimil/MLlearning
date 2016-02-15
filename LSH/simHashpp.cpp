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

simHashpp::simHashpp(const string& str,int tokenSize){
	hash=simHash(str.c_str(),tokenSize);
}

int simHashpp::hammingDist(const simHashpp& other) const{
	return ::hammingDist(hash,other.getHash());
}

float simHashpp::similarity(const simHashpp& other) const{
	float fa=(float)hash;
	float fb=(float)other.getHash();
	if (fa>fb)
		return fb/fa;
	return fa/fb;
}

unsigned simHashpp::getHash() const{
	return hash;
}

