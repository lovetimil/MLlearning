/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#pragma once

#include <set>
#include <vector>
#include <algorithm>

template<class T>
class apriori{
private:
	typedef std::vector<T> vctData;
	typedef std::vector<vctData> dataMap;
	typedef dataMap retMap;
	typedef typename vctData::iterator vctIter;
	retMap ret;
	float minSupport_;
	static float calcSupport(vctData setData,const dataMap& dMap);
	void scApriori(vctData nowData,const vctData& uqeData,
	const dataMap& dMap,retMap& toWrite,vctIter last);
public:
	apriori(const dataMap& dMap,double minSupport);
	const retMap& getResult(){ return ret; }
};

#include "apriori.cpp"
