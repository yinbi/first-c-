#ifndef LIST_H
#define LIST_H
#include "Box.h"
//class Package
//{
//public:
//	//Package();
//	//~Package();
//	Package(Box* pNewBox);
//	Box* getBox() const ;
//	Package* getNext() const ;
//	void setNext(Package* pPackage);
//
//private:
//	Box* pBox;
//	Package* pNext;
//};

class TruckLoad
{
public:
	TruckLoad(Box* pBox=0,int count=1);
	//副本构造函数
	TruckLoad(const TruckLoad& Load);
	Box* getFirstBox();
	Box* getNextBox();
	void addBox(Box* pBox);
	//TruckLoad();
	~TruckLoad();

private:
	class Package
	{
	public:
		//Package();
		~Package();
		Package(Box* pNewBox);
		Box* getBox() const ;
		Package* getNext() const ;
		void setNext(Package* pPackage);

		Box* pBox;
		Package* pNext;
	};
	Package* pHead;
	Package* pTail;
	Package* pCurrent;

};
#endif // !LIST_H