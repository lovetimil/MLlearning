/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#pragma once

#include <string>
#include <vector>

class simHashpp{
private:
	unsigned hash;
public:
	explicit simHashpp(const std::string& str,int tokenSize=2);
	explicit simHashpp(const std::vector<std::string>& tokens);
	int hammingDist(const simHashpp& other) const;
	float similarity(const simHashpp& other) const;
	unsigned getHash() const;
};

