#include "stdafx.h"
#include "print.h"
extern int num1;
//void print_fun::print(const string& s){
//	data::num++;
//	num1++;
//	cout << s << endl;
//	cout << "data::num=" << data::num << endl;
//}

void print_fun1::print(const string& s){
	data::num++;
	num1++;
	cout << "print_fun1Êä³ö" << endl;
	cout << s << endl;
	cout << "data::num=" << data::num << endl;
}

void print_fun2::print(const string& s){
	data::num++;
	num1++;
	cout << "print_fun2Êä³ö" << endl;
	cout << s << endl;
	cout << "data::num=" << data::num << endl;
}