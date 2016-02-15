/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#pragma once

#include <string>

class simHasher{
private:
	unsigned hash;
public:
	simHasher(const std::string& str,int tokenSize=2);
	int hammingDist(const simHasher& other) const;
	float similarity(const simHasher& other) const;
	unsigned getHash() const;
};

