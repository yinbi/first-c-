#include <cstring>
#include "ErrorMessage.h"


ErrorMessage::ErrorMessage(const char* pText)
{
	pMessage=new char[strlen(pText)+1];
	strcpy(pMessage,pText);
}

ErrorMessage::~ErrorMessage()
{
	cout << endl << "Destructor Called." << endl;
	delete[] pMessage;
}
void ErrorMessage::resetMessage()
{
	for (char* temp = pMessage; *temp !='\0'; temp++)
	{
		*temp='*';
	}
}
//ErrorMessage& ErrorMessage::operator=(const ErrorMessage& message)
//{
//	if(this == &message)
//	{
//		return *this;
//	}
//	delete[] pMessage;
//	pMessage=new char[strlen(message.pMessage)+1];
//	std::strcpy(pMessage,message.pMessage);
//	return *this;
//}