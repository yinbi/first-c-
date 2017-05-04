//#include "TruckLoad.h"
//
//TruckLoad::TruckLoad(Box* pBox,int count){
//	pHead=pTail=pCurrent=0;
//	if((count>0)&&(pBox!=0)){
//		for (int i = 0; i < count; i++){
//			addBox(pBox+i);
//		}
//	}
//}
//
//void TruckLoad::addBox(Box* pBox){
//	Package* pPackage=new Package(pBox);	//create a Package
//	if(pHead){
//		pTail->setNext(pPackage);
//	}
//	else{
//		pHead=pPackage;
//	}
//	pTail=pPackage;
//}
//
//Box* TruckLoad::getFirstBox(){
//	pCurrent=pHead;
//	return pCurrent->getBox();
//}
//
//Box* TruckLoad::getNextBox(){
//	if(pCurrent){
//		pCurrent=pCurrent->getNext();
//	}
//	else{
//		pCurrent=pHead;
//	}
//	return pCurrent?pCurrent->getBox():0;
//}