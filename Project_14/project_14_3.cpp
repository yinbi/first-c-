#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

#include "ErrorMessage.h"

int main()
{
	ErrorMessage waring("There is a serious problem here");
	ErrorMessage standard;

	cout << endl << "warning contains --" << waring.what();
	cout << endl << "standard contains --" << standard.what();

	standard=waring;

	cout << endl << "After assigning the value of standard,standard contains--" << standard.what();

	cout << endl << "Resetting warning ,not standard" << endl;
	waring.resetMessage();

	cout << endl << "warning now contains --" << waring.what();
	cout << endl << "standard now contains --" << standard.what();


	cout << endl << "请输入一个数:" ;
	char c;
	std::cin >> c;
	return 0;
}
