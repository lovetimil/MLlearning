/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#pragma once

#include <string>

class simHashpp{
private:
	unsigned hash;
public:
	simHashpp(const std::string& str,int tokenSize=2);
	int hammingDist(const simHashpp& other) const;
	float similarity(const simHashpp& other) const;
	unsigned getHash() const;
};

