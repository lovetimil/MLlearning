/*
	The MIT License (MIT)
	Copyright (c) <2016> <Darksun2010>
*/

#pragma once

const int hashSize=32;


unsigned int BKDRHash(const char* str);
unsigned int simHash(const char* str,int tokenSize);
unsigned int simHash_tokens(const char** tokens,int amount);
int hammingDist(unsigned int a,unsigned int b);

