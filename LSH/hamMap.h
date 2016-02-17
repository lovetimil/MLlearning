/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#pragma once

#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
extern "C"{
#include "simHash.h" //for hashSize,hammingDist
}

class hamMap{
private:
	static const int hashSize=::hashSize;
	std::unordered_multimap<unsigned,std::string> M;
	std::unordered_multimap<unsigned,unsigned> D;
	int perSeg,segAmount,maxHamDist_;
	std::vector<unsigned> split(unsigned toSplit);
public:
	typedef std::pair<unsigned,std::string> KV;
	explicit hamMap(int maxHamDist=3); //make sure (maxHamDist+1)|hashSize
	void insert(const KV& kv);
	void insert(const std::string& k);
	int count(unsigned sh);
	int count(const std::string& k);
	std::vector<std::string> find(unsigned sh);
	std::vector<std::string> find(const std::string& k);
};

