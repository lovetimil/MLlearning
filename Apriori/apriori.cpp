/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/
	
#pragma once

template<class T>
float apriori<T>::calcSupport(vctData setData,const dataMap& dMap){
	int supportCnt=0;
	std::sort(setData.begin(),setData.end());
	for (const auto& _:dMap){
		vctData groupData(_);
		std::sort(groupData.begin(),groupData.end());
		vctData tmp;
		std::set_difference(setData.begin(),setData.end(),
		groupData.begin(),groupData.end(),back_inserter(tmp));
		if (tmp.size()==0)
			supportCnt++;
	}
	return (float)supportCnt/dMap.size();
}

template<class T>
void apriori<T>::scApriori(vctData nowData,const vctData& uqeData,
const dataMap& dMap,retMap& toWrite,vctIter last){
	if (calcSupport(nowData,dMap)<minSupport_)
		return ;
	toWrite.push_back(nowData);
	for (auto it=last;it!=uqeData.end();++it){
		nowData.push_back(*it);
		scApriori(nowData,uqeData,dMap,toWrite,it);
		nowData.pop_back();
	}
}

template<class T>
apriori<T>::apriori(const dataMap& dMap,double minSupport):minSupport_(minSupport){
	std::set<T> uniqueData;
	auto insertUD=[&](const T& data){ uniqueData.insert(data); };
	auto insertVD=[&](const vctData data)
	{ for_each(data.begin(),data.end(),insertUD); };
	for_each(dMap.begin(),dMap.end(),insertVD);
	vctData initSet(uniqueData.begin(),uniqueData.end());
	for (auto it=initSet.begin();it!=initSet.end();++it)
		scApriori(vctData(it,it+1),initSet,dMap,ret,it);
}
