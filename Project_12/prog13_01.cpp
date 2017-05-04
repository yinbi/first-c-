#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

#include "Box.h"
#include "List.h"

inline int random(int count){
	return 1 + static_cast<int>(count*static_cast<double>(std::rand()) / (RAND_MAX+1.0) );
}
Box* maxBox(TruckLoad& Load){
	Box* pBox=Load.getFirstBox();
	Box* pNextBox;
	while (pNextBox=Load.getNextBox()){
		/*if(pBox->compareVolume(*pNextBox)<0){
			pBox=pNextBox;
		}*/
		//运算符重载
		if(*pBox< *pNextBox){
			pBox=pNextBox;
		}
		
	}
	return pBox;
}
int main(){
	////upper limit on Box dimensions
	//const int dimLimit=100;		
	////initialize the random number generator
	//std::srand((unsigned) std::time(0));

	////create an empty list
	//TruckLoad load1;

	////add 10 random sized Box objects to the list
	//for (int i = 0; i < 10; i++){
	//	load1.addBox(new Box(random(dimLimit),random(dimLimit),random(dimLimit)));
	//}

	////find the largest box in the list
	//Box* pBox=load1.getFirstBox();
	//Box* pNextBox;

	////assign and then test pointer to next box
	//while (pNextBox=load1.getNextBox()){
	//	if(pBox->compareVolume(*pNextBox)<0){
	//		pBox=pNextBox;
	//	}
	//}

	//cout << endl
	//	 << "The largest box in the first list is "
	//	 << pBox->getLength() << " by "
	//	 << pBox->getWidth() << " by "
	//	 << pBox->getHeight() << endl;


	////-------------------------------------------
	////Number of elements in box array
	//const int boxCount=20;
	//Box boxes[boxCount];
	//for (int i = 0; i < boxCount; i++){
	//	boxes[i]=Box(random(dimLimit),random(dimLimit),random(dimLimit));
	//}
	//TruckLoad load2(boxes,boxCount);
	////find the largest box int the list
	//pBox==load2.getFirstBox();
	//while (pNextBox=load2.getNextBox()){
	//	if(pBox->compareVolume(*pNextBox)<0){
	//		pBox=pNextBox;
	//	}
	//}
	//cout << endl
	//	 << "The largest box in the first list is "
	//	 << pBox->getLength() << " by "
	//	 << pBox->getWidth() << " by "
	//	 << pBox->getHeight() << endl;

	////delete the box objects in the first list
	//pNextBox=load1.getFirstBox();
	//while (pNextBox){
	//	delete pNextBox;
	//	pNextBox=load1.getNextBox();
	//}
	////-------------------------------------------


	//upper limit on Box dimensions
	const int dimLimit=100;		
	//initialize the random number generator
	std::srand((unsigned) std::time(0));
	//create an empty list
	TruckLoad load1;

	//add 3 random sized Box objects to the list
	for (int i = 0; i < 3; i++){
		load1.addBox(new Box(random(dimLimit),random(dimLimit),random(dimLimit)));
	}
	Box* pBox=maxBox(load1);


	cout << endl
		 << "The largest box in the first list is "
		 << pBox->getLength() << " by "
		 << pBox->getWidth() << " by "
		 << pBox->getHeight() << " address "
		 << pBox << endl;

	TruckLoad load2(load1);

	pBox=maxBox(load2);
	cout << endl
		 << "The largest box in the second list is "
		 << pBox->getLength() << " by "
		 << pBox->getWidth() << " by "
		 << pBox->getHeight() << " address "
		 <<pBox << endl;
	

	//add 5 more boxes to the second list
	for (int i = 0; i < 5; i++){
		load2.addBox(new Box(random(dimLimit),random(dimLimit),random(dimLimit)));
	}
	pBox=maxBox(load2);
	cout << endl
		 << "The largest box in the extended second list is "
		 << pBox->getLength() << " by "
		 << pBox->getWidth() << " by "
		 << pBox->getHeight() << " address "
		 <<pBox << endl;

	//count the number of boxes in the first list and display count
	Box* pNextBox=load1.getFirstBox();
	int count=0;
	while (pNextBox){
		count++;
		pNextBox=load1.getNextBox();
	}
	cout << endl << "first list still contains " << count << " Box objects." << endl;

	//count the number of boxes in the second list and display count
	pNextBox=load2.getFirstBox();
	int count2=0;
	while (pNextBox){
		count2++;
		pNextBox=load2.getNextBox();
	}
	cout << endl << "second list still contains " << count2 << " Box objects." << endl;

	//delete the boxes objects in the free store
	pNextBox=load2.getFirstBox();
	while (pNextBox){
		delete pNextBox;
		pNextBox=load2.getNextBox();
	}




	cout << "请输入一个数:" ;
	char c;
	std::cin >> c;
	return 0;
}