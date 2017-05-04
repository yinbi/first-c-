#ifndef CARTON_H
#define CARTON_H
#include "Box.h"
class Carton : public Box
{
public:
	Carton(const char* pStr="Cardboard");
	
	~Carton();

private:
	char* pMaterial;
};


#endif // !CARTON_H
