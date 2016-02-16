/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "hamMap.h"
#include "simHashpp.h"

int main(void){
	using namespace std;
	string fName;
	getline(cin,fName);
	ifstream stm(fName.c_str(),ios::in);
	string x;
	hamMap M;
	int t=0;
	while (t++,getline(stm,x)){
		istringstream stmSs(x);
		string x1;
		vector<string> tkns;
		while (stmSs>>x1)
			tkns.push_back(x1);
		simHashpp hasher(tkns);
		auto v=M.find(hasher.getHash());
		cout<<"similar to ["<<t<<"]:"<<endl;
		copy(v.begin(),v.end(),ostream_iterator<string>(cout,"\n"));
		cout<<"("<<v.size()<<" counts)"<<endl;
		M.insert(make_pair(hasher.getHash(),x));
	}
	return 0;
}

