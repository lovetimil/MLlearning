/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#pragma once

#include <vector>
#include <stdexcept>

template<class TKey,class TValue>
class kNN{
private:
	std::vector<std::pair<std::vector<TKey>,TValue> > _sample;
	int _k;
	static int getDistance(const std::vector<TKey>& k1,const std::vector<TKey>& k2);
public:
	kNN(const std::vector<std::pair<std::vector<TKey>,TValue> >& sample,int k=3):
	_sample(sample),_k(k){
		if (sample.size()<k)
			throw std::invalid_argument("Invalid k");
	}
	kNN(int k=3):_k(k){}
	void modifyK(int k){ _k=k; }
	void feed(const std::vector<TKey>& data,TValue answer){
		_sample.emplace_back(data,answer);
	}
	TValue getAnswer(const std::vector<TKey>& inX);
};

#include "kNN.cpp" //implementation
