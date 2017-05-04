#include "stdafx.h"
#include "print_that.h"
#include "print_this.h"
#define DO_THIS


void value_input(int num1,int num2);
bool isNumber(const char* ch);
extern int num1=1;
int data::num=0; //定义全局变量
int main(int argc, _TCHAR* argv[]){
	string s="string123456";
	#ifdef DO_THIS
	#define PRINT(abc) print_this_fun::print_this(#abc)
		//print_this_fun::print_this(s+"_");
	#else
	#define PRINT(abc) print_that_fun::print_that(#abc)
		//print_that_fun::print_that(s);
	#endif // DO_THIS
	PRINT(abc);
	cout << "main_print:" << endl;
	cout << "data::num=" << data::num << endl;
	cout << "extern int num1=" << num1 << endl;
	value_input(1,2);
}

void value_input(int num1,int num2){
	string str;
	bool flag=false;
	while(!flag){
		cout << "请输入一个数:" ;
		cin >> str;
		flag=isNumber(str.c_str());
	}
	
}
bool isNumber(const char* ch){
	 int len= strlen(ch);
	 for(int i=0; i<len; i++){
		if(*(ch+i)<'0' || *(ch+i)>'9'){
			cout << "输入为非数字" << endl ;
			return false;
		}
	 }
	 return true;
}