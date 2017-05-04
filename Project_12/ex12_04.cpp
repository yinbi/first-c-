//#include <iostream>
//#include "Box.h"
//
//using std::cout;
//using std::endl;
//using std::cin;
//
//int compareVolume(Box& box1,Box& box2);
//int main(){
//	cout << endl;
//
//	/*Box firstbox(2.2,1.1,0.5);
//	Box secondbox;
//	Box* pthirdbox=new Box(15.0,20.0,8.0);
//	
//	cout << "volume of second box=" 
//		 << secondbox.volume()
//		 << endl;
//	
//	cout << "volume of third box=" 
//		 << pthirdbox->volume()
//		 << " or "
//		 << (*pthirdbox).volume()
//		 << endl;
//
//	delete pthirdbox;
//	cout << endl;*/
//
//	Box	firstbox(2.2,1.1,0.5);
//	Box secondbox(firstbox);
//	Box* pthirdbox=new Box(15.0,20.0,8.0);
//	cout << "volume of second box=" 
//		 << firstbox.volume()
//		 << endl;
//	
//	cout << "volume of third box=" 
//		 << secondbox.volume()
//		 << endl;
//
//	cout << "Surface area of third box=" 
//		 << boxSurface(*pthirdbox)
//		 << endl;
//
//	cout << "the first box is "
//		 << (firstbox.compareVolume(secondbox) >0? "":"not ")
//		 << "greater than the second box"
//		 << endl;
//
//	cout << "the first box is "
//		 <<  (compareVolume(firstbox,secondbox)>0? "":"not ")
//		 << "greater than the second box"
//		 << endl;
//
//	cout << "object count is "
//		 << firstbox.getObjectCount()
//		 << endl;
//	
//	delete pthirdbox;
//	
//	cout << "请输入一个数:" ;
//	char c;
//	cin >> c;
//	return 0;
//}
//
