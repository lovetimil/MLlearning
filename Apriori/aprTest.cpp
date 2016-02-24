/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include "apriori.hpp"
#include <stdio.h>
#include <vector>

int main(void){
	int n;
	scanf("%d",&n);
	int cnt=0;
	std::vector<std::vector<int>> v(n);
	while (n--){
		int m;
		scanf("%d",&m);
		for (int i=0;i<m;++i){
			int x;
			scanf("%d",&x);
			v[cnt].push_back(x);
		}
		cnt++;
	}
	apriori<int> aTest(v,0.5);
	for (const auto& _:aTest.getResult()){
		for (const auto& __:_)
			printf("%d ",__);
		puts("");
	}
	return 0;
}