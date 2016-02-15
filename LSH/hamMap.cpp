/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "hamMap.h"

std::vector<unsigned> hamMap::split(unsigned toSplit){
	std::vector<unsigned> ret;
	for (int i=0;i<hashSize;){
		int tmp=0;
		for (int j=0;j<perSeg;++i)
			tmp+=toSplit&(1<<i);
		ret.push_back(tmp);
	}
	return ret;
}

hamMap::hamMap(int maxHamDist){
	if (hashSize%(maxHamDist+1))
		throw std::invalid_argument("Invalid maxHamDist");
	maxHamDist_=maxHamDist;
	perSeg=hashSize/(maxHamDist+1),segAmount=maxHamDist+1;
}

void hamMap::insert(const KV& kv){
	M.insert(kv);
	auto vct=split(kv.first);
	for (unsigned x:vct)
		D.insert(std::make_pair(x,kv.first));
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

std::vector<std::string> hamMap::find(unsigned sh){
	std::vector<std::string> ret;
	auto vct=split(sh);
	for (unsigned x:vct){
		auto range=D.equal_range(x);
		for (auto it=range.first;it!=range.second;++it)
			if (hammingDist(it->second,sh)<=maxHamDist_)
				ret.push_back(M[it->second]);
	}
	std::sort(ret.begin(),ret.end());
	return std::vector<std::string>(ret.begin(),
									std::unique(ret.begin(),ret.end()));
}
