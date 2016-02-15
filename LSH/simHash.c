/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#include "simHash.h"
#include "string.h"
#include "stdlib.h"

unsigned int BKDRHash(const char* str){
	const unsigned int seed=131;
	unsigned int hash=0;
	while (*str)
		hash=hash*seed+(*str++);
	return (hash&0x7FFFFFFF);
}

unsigned int simHash(const char* str,int tokenSize){
	int ret[hashSize];
	char* strBuf=(char*)malloc(sizeof(char)*(tokenSize+1));
	int len=strlen(str);
	int i=0,bitMask;
	memset(ret,0,sizeof(ret));
	for (;i<len;i+=tokenSize){
		memcpy(strBuf,str+i,tokenSize);
		*(strBuf+i+tokenSize)='\0';
		unsigned int tokenHash=BKDRHash(strBuf);
		for (bitMask=0;bitMask<hashSize;++bitMask)
			if (tokenHash&(1<<bitMask))
				ret[bitMask]++; //what is the weight?
			else ret[bitMask]--;
	}
	free(strBuf);
	unsigned int retNum=0;
	for (i=0;i<hashSize;++i)
		if (ret[i]>0)
			retNum+=1<<i;
	return retNum;
}

int hammingDist(unsigned int a,unsigned int b){
	unsigned x=a^b;
	int ret=0;
	while (x){
		ret++;
		x&=x-1;
	}
	return ret;
}
