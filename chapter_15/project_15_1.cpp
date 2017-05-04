#include <iostream>
#include "Box.h"
#include "Carton.h"

using std::cout;
using std::endl;

int main(){
	Box myBox(40.0,30.0,20.0);
	Carton myCarton;
	Carton candyCarton("Thin Cardboard");
	

	cout << endl
		 << "mybox occupies " << sizeof myBox << "bytes" << endl;
	cout << "myCarton occupies " << sizeof myCarton << "bytes" << endl;
	cout << "candyCarton occupies " << sizeof candyCarton << "bytes" << endl;

	cout << endl
		 << "mybox volume is " << myBox.volume() << endl;
	cout << "myCarton volume is " << myCarton.volume() << endl;
	cout << "candyCarton volume is " << candyCarton.volume() << endl;

	cout << endl << "请输入一个数:" ;
	char c;
	std::cin >> c;
	return 0;

}