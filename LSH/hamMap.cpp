/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <unordered_set>
#include "hamMap.h"
#include "simHashpp.h"

static void splitStringBySpace(const std::string& str,
							   std::vector<std::string>& dst){
	std::istringstream ss(str);
	std::string tmp;
	while (ss>>tmp)
		dst.push_back(tmp);
}

static unsigned getHashBystring(const std::string& str){
	std::vector<std::string> tmp;
	splitStringBySpace(str,tmp);
	simHashpp hasher(tmp);
	return hasher.getHash();
}

std::vector<unsigned> hamMap::split(unsigned toSplit){
	std::vector<unsigned> ret;
	for (int i=0;i<hashSize;){
		int tmp=0;
		for (int j=0;j<perSeg;++j,++i)
			tmp+=toSplit&(1<<i);
		ret.push_back(tmp);
	}
	return ret;
}

hamMap::hamMap(int maxHamDist){
	if (hashSize%(maxHamDist+1))
		throw std::invalid_argument("Invalid maxHamDist");
	maxHamDist_=maxHamDist;
	perSeg=hashSize/(maxHamDist+1);
	segAmount=maxHamDist+1;
}

void hamMap::insert(const KV& kv){
	M.insert(kv);
	auto vct=split(kv.first);
	for (unsigned x:vct)
		D.insert(std::make_pair(x,kv.first));
}

void hamMap::insert(const std::string& k){
	insert(std::make_pair(getHashBystring(k),k));
}

int hamMap::count(unsigned sh){
	int cnt=0;
	auto vct=split(sh);
	for (unsigned x:vct){
		auto range=D.equal_range(x);
		for (auto it=range.first;it!=range.second;++it)
			if (hammingDist(it->second,sh)<=maxHamDist_)
				cnt++;
	}
	return cnt;
}

int hamMap::count(const std::string& k){
	return count(getHashBystring(k));
}

std::vector<std::string> hamMap::find(unsigned sh){
	std::unordered_set<std::string> ret;
	auto vct=split(sh);
	for (unsigned x:vct){
		auto range=D.equal_range(x);
		for (auto it=range.first;it!=range.second;++it)
			if (hammingDist(it->second,sh)<=maxHamDist_){
				auto range=M.equal_range(it->second);
				for (auto it=range.first;it!=range.second;++it)
					ret.insert(it->second);
			}
	}
	return std::vector<std::string>(ret.begin(),ret.end());
}

std::vector<std::string> hamMap::find(const std::string& k){
	return find(getHashBystring(k));
}

