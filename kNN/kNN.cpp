/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#pragma once

#include "kNN.hpp"
#include <map>
#include <array>
#include <cmath>
#include <algorithm>

template<class TKey,class TValue>
TValue kNN<TKey,TValue>::getAnswer(const std::vector<TKey>& inX){
	std::vector<std::pair<int,TValue> > dist;
	for (const auto& x:_sample){
		if (x.first.size()!=inX.size())
			throw std::invalid_argument("Invalid feature");
		dist.push_back(std::make_pair(getDistance(x.first,inX),x.second));
	}
	std::sort(dist.begin(),dist.end());
	std::map<TValue,int> timeSet;
	for (int i=0;i<_k;++i){
		auto it=timeSet.find(dist[i].second);
		if (it!=timeSet.end())
			*it++;
		else timeSet.insert(std::make_pair(dist[i].second,1));
	}
	return timeSet.begin()->first;
}

template<class TKey,class TValue>
int kNN<TKey,TValue>::getDistance(const std::vector<TKey>& k1,const std::vector<TKey>& k2){
	int ans=0;
	for (unsigned i=0;i<k1.size();++i)
		ans+=(k1[i]-k2[i])*(k1[i]-k2[i]);
	return ans;
}
