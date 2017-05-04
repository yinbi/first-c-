#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H
#include <iostream>
using namespace std;

class ErrorMessage
{
public:
	ErrorMessage(const char* pTest="Error");
	~ErrorMessage();
	void resetMessage();
	char* what() const { return pMessage; }
	//ErrorMessage& operator=(const ErrorMessage& Message);


private:
	char* pMessage;
};



#endif // !ERRORMESSAGE_H

