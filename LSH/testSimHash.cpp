/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "simHashpp.h"

int main(void){
	using namespace std;
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	simHashpp sh1(s1),sh2(s2);
	cout<<"simHash(s1): "<<sh1.getHash()<<endl;
	cout<<"simHash(s2): "<<sh2.getHash()<<endl;
	cout<<"hammingDist of s1 and s2: "<<sh1.hammingDist(sh2)<<endl;
	cout<<fixed<<"similarity of s1 and s2: "<<sh1.similarity(sh2)<<endl;
	cout<<endl;
	istringstream ss1(s1),ss2(s2);
	string x;
	vector<string> vs1,vs2;
	while (ss1>>x)
		vs1.push_back(x);
	while (ss2>>x)
		vs2.push_back(x);
	simHashpp sht1(vs1),sht2(vs2);
	cout<<"simHash(s1): "<<sht1.getHash()<<endl;
	cout<<"simHash(s2): "<<sht2.getHash()<<endl;
	cout<<"hammingDist of s1 and s2: "<<sht1.hammingDist(sht2)<<endl;
	cout<<fixed<<"similarity of s1 and s2: "<<sht1.similarity(sht2)<<endl;
	return 0;
}

