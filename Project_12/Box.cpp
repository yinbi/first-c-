#include <iostream>
#include "Box.h"

using std::cout;
using std::endl;

//构造函数初始化列表
Box::Box(double lvalue,double wvalue,double hvalue):
	length(lvalue),width(wvalue),height(hvalue){
	++objectCount;
	cout << "Box constructor called" << endl;
	if(length<=0.0){
		length=1.0;
	}
	if(width<=0.0){
		width=1.0;
	}
	if(height<=0.0){
		height=1.0;
	}
}

double Box::volume() const{
	//length=1;
	//cout << "length=" << length;
	return length*width*height;
}

int Box::compareVolume(const Box& otherBox){
	double vol1=this->volume();
	double vol2=otherBox.volume();
	return vol1>vol2?1:(vol1<vol2?-1:0);
}

double Box::getHeight() const{
	return length;
}

double Box::getLength() const{
	return length;
}

double Box::getWidth() const{
	return width;
}

Box::~Box(){
	cout << "Box distructor called." << endl;
}

int Box::objectCount=0;


double boxSurface(const Box& theBox){
	return 2.0*(theBox.height*theBox.width);
}
//局外函数
int compareVolume(Box& box1,Box& box2){
	double vol1=box1.volume();
	double vol2=box2.volume();
	return vol1>vol2?1:(vol1<vol2?-1:0);
}