#include "Box.h"
Box::Box(double lv,double wv,double hv):length(lv),width(wv),height(hv)
{
}
double box::volume() const{
	return length*width*height;
}

Box::~Box()
{
}
