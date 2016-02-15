/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include <string>
#include <vector>
extern "C"{
#include "simHash.h"
}
#include "simHashpp.h"

using std::string;
using std::vector;

simHashpp::simHashpp(const string& str,int tokenSize){
	hash=simHash(str.c_str(),tokenSize);
}

simHashpp::simHashpp(const vector<string>& tokens){
	const char** tokenPtr=new const char*[tokens.size()];
	for (unsigned i=0;i<tokens.size();++i)
		tokenPtr[i]=tokens[i].c_str();
	hash=simHash_tokens(tokenPtr,tokens.size());
	delete[] tokenPtr;
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

