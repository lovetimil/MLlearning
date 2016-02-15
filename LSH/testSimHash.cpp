/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include <iostream>
#include <string>
#include "simHashpp.h"
using namespace std;

int main(void){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	simHashpp sh1(s1),sh2(s2);
	cout<<"simHash(s1): "<<sh1.getHash()<<endl;
	cout<<"simHash(s2): "<<sh2.getHash()<<endl;
	cout<<"hammingDist of s1 and s2: "<<sh1.hammingDist(s2)<<endl;
	cout<<fixed<<"similarity of s1 and s2: "<<sh1.similarity(s2)<<endl;
	return 0;
}

