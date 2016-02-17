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
		*(strBuf+tokenSize)='\0';
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

unsigned int simHash_tokens(const char** tokens,int amount){
	int ret[hashSize],bitMask,i;
	memset(ret,0,sizeof(ret));
	for (i=0;i<amount;++i){
		unsigned int tokenHash=BKDRHash(tokens[i]);
		for (bitMask=0;bitMask<hashSize;++bitMask)
			if (tokenHash&(1<<bitMask))
				ret[bitMask]+=strlen(tokens[i]);
			else ret[bitMask]-=strlen(tokens[i]);
	}
	unsigned int retNum=0;
	for (i=0;i<hashSize;++i)
		if (ret[i]>0)
			retNum+=1<<i;
	return retNum;
}

static int bitCount(unsigned int n){
    n=(n &0x55555555)+((n>>1)&0x55555555);
    n=(n &0x33333333)+((n>>2)&0x33333333);
    n=(n &0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
    n=(n &0x00ff00ff)+((n>>8)&0x00ff00ff);
    n=(n &0x0000ffff)+((n>>16)&0x0000ffff);
    return n;
}

int hammingDist(unsigned int a,unsigned int b){
	return bitCount(a^b);
}
