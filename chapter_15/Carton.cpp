#include "Carton.h"
#include <iostream>
#include <cstring>

Carton::Carton(const char* pStr){
	pMaterial=new char[strlen(pStr)+1];
	//std::strcpy(pMaterial,pStr);
	strcpy_s(pMaterial,strlen(pStr)+1,pStr);
}



Carton::~Carton()
{
	delete[] pMaterial;
}
