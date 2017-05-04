#include "Box.h"
#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

TruckLoad::Package::Package(Box* pNewBox):pBox(pNewBox),pNext(0){}

Box* TruckLoad::Package::getBox() const{return pBox;}

TruckLoad::Package* TruckLoad::Package::getNext() const{return pNext;}

void TruckLoad::Package::setNext(Package* pPackage){pNext=pPackage;}

TruckLoad::TruckLoad(Box* pBox,int count){
	pHead=pTail=pCurrent=0;
	if((count>0)&&(pBox!=0)){
		for (int i = 0; i < count; i++){
			addBox(pBox+i);
		}
	}
}

//code to create a duplicate of the object Load
TruckLoad::TruckLoad(const TruckLoad& Load){
	pHead=pTail=pCurrent=0;
	if(Load.pHead==0) 
		return;
	Package* pTemp=Load.pHead;
	do{
		addBox(pTemp->pBox);
	} while (pTemp=pTemp->pNext);
}

void TruckLoad::addBox(Box* pBox){
	Package* pPackage=new Package(pBox);	//create a Package
	if(pHead){
		pTail->setNext(pPackage);
	}
	else{
		pHead=pPackage;
	}
	pTail=pPackage;
}

Box* TruckLoad::getFirstBox(){
	pCurrent=pHead;
	return pCurrent->getBox();
}

Box* TruckLoad::getNextBox(){
	if(pCurrent){
		pCurrent=pCurrent->getNext();
	}
	else{
		pCurrent=pHead;
	}
	return pCurrent?pCurrent->getBox():0;
}

TruckLoad::~TruckLoad(){
	cout << "TruckLoad distructor called." << endl;
	while (pCurrent=pHead->pNext)
	{
		delete pHead;
		pHead=pCurrent;
	}
	delete pHead;
}

TruckLoad::Package::~Package(){
	cout << "Package distructor called." << endl;
}