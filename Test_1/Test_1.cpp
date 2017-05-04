// Test_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#include <ctype.h>
//关闭断言机制 必须放在#include <cassert>之前
#define NDEBUG
#include <cassert>
#include "data.h"
#include "compare.h"
#include "functions.h"

#define TESTINDEX


//int random(int count){
//
//}
//int _tmain(int argc, _TCHAR* argv[])
//{
//    
//	return 0;
//}
//#include <stdio.h>
using namespace std;
double power(double x,int n);
void value_input(int num1,int num2);
bool isNumber(const char* ch);
char* reversalStr(const char* ch);
int& do_it(int& num);
template <class T> T larger(T a,T b);
void swap(string* pstr[],int first,int second);
int count_words(const string& text,const string& separators);
void extract_words(string* pstr[],const string& text,const string& separators);
void show_words(string* pstr[],int count);
void sort(string* pstr[],int start,int end);
int Partition(string* pstr[],int start,int end);
template <class T> T plus(T a,T b);
//template <> string plus<string>(string str1,string str2);
namespace data{
	extern const double pi;
}
int main(int argc, _TCHAR* argv[])
{
	
	/*cout << "hello world";
	int num1=10;
	int result=0;
	result=2+num1++;
	cout << result;
	cout << num1 << endl;
	cout << rand() << " " << rand() << " " << rand() << endl;
	srand((int)time(0));
	cout << rand() << " " << rand() << " " << rand() << endl;
	int random_value = rand();
	cout << random_value;*/

	//float value1 = 0.1f;
	//float value2 = 2.1f;
	//value1 -= 0.09f;
	//value2 -= 2.09f;
	//cout << "value1=" << value1 << endl;
	//cout << "value2=" << value2 << endl;
	//cout << value1-value2 << endl;
	//return 0;

	//cout << endl << sizeof(double) << endl;
	//cout << endl << numeric_limits<double>::max() << endl;
	//cout << endl << numeric_limits<double>::min() << endl;
	////返回二进制数字的位数
	//cout << endl << numeric_limits<char>::digits << endl;

	//cout << endl << sizeof(unsigned long) << endl;

	/*unsigned long red=0xFF0000UL;
	unsigned long white=0xFFFFFFUL;
	cout << hex;
	cout << setfill('0');
	cout << "         red=" << setw(8) << red << endl;
	cout << "        ~red=" << setw(8) << ~red << endl;
	cout << "       white=" << setw(8) << white << endl;
	cout << "      ~white=" << setw(8) << ~white << endl;
	cout << " red & white=" << setw(8) << (red & white) << endl;
	cout << " red | white=" << setw(8) << (red | white) << endl;
	unsigned long mask=red ^ white;
	cout << "mask=red^white=" << setw(8) << mask << endl;
	cout << "  mask ^ red=" << setw(8) << (mask ^ red) << endl;
	cout << "mask ^ white=" << setw(8) << (mask ^ white) << endl;
	unsigned long flags=0xff;
	unsigned long bit1mask=0x1;
	unsigned long bit6mask=0x20;
	unsigned long bit20mask=0x80000;
	cout << "flags & bit1mask=" << setw(8) << (flags & bit1mask) << endl;
	cout << "flags & bit6mask=" << setw(8) << (flags & bit6mask) << endl;
	cout << "flags |= bit20mask=" << setw(8) << (flags |= bit20mask) << endl;*/
	
	
	//int result=0;
	//int age=0;
	//cout << "请输入一个整数" << endl;
	//cin >> age;
	//cout << "age=" << age << endl;
	//int mask=~0 - 1;
	//result=age & mask;//去掉最后一位
	//result +=~age & 1;//~age & 1最后一位取反
	//cout << "mask=" << mask << endl;
	//cout << "result=" << result << endl;
	//cout << "16进制输出:" << endl;
	//cout << hex;
	//cout << "age=" << age << endl;
	//cout << "mask=" << mask << endl;
	//cout << "result=" << result << endl;

	int result=102009;
	cout << "result=";
	cout << hex;
	cout << result;
	cout << endl;
	cout << "result=";
	cout << dec;
	cout << result;

	//int i=0;
	//char c;
	//unsigned int box=0U;
	//while(i<4)
	//{
	//	cout << "请输入第" << ++i << "个字符" << endl;
	//	cin >> c;
	//	cout << "ASCII:" << static_cast<int>(c) << endl;
	//	if(i==1){
	//		box= box | static_cast<int>(c);
	//	}else{
	//		box=box | (static_cast<int>(c) << (i-1)*8);
	//	}
	//}
	//cout << box << endl;
	//cout << "16进制输出:" << endl;
	//cout << hex << showbase;
	//cout << box << endl;
	//cout << "反转输出" << endl;
	////Ox64636261
	//int j=0;
	//while(j<4)
	//{
	//	cout << "num=" << (box << (j*8) & ~0 << 24) << endl;
	//	cout << static_cast<char>((box << (j*8) & ~0 << 24)>>24) << endl;
	//	j++;
	//}

	/*double carrots[3][4]={0};
	cout << carrots << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(carrots[0][0]) << endl;
	cout << sizeof(carrots[0]) << endl;*/


	/*string text="Smith,where Jones had had \"had had\", had had \"had\". \"Had had\" had had the examiners' approval. ";
	string separators=" ,.\"";
	size_t start=text.find_first_not_of(separators);
	size_t end=0;
	int word_count=0;
	while(start != string::npos){
		end=text.find_first_of(separators,start+1);
		if(end == string::npos){
			end=text.length();
		}
		cout << text.substr(start,end-start) << endl;
		word_count++;
		start=text.find_first_not_of(separators,end+1);
	}
	cout << "word:" << word_count << endl;*/
    
	/*string str1="we can insert a string.";
	string str2="a string into";
	str1.insert(14,str2);
	cout << str1 << endl;*/

	/*long number=12345L;
	long* pnumber;
	pnumber=&number;
	cout << *pnumber << endl;*/

	/*const char* pstar1="Mae west";
	cout << pstar1 << endl;
	cout << *pstar1 << endl;*/

	//string text;
	//const string separators=" ,.\"\n";
	//const int max_words=1000;
	//string words[max_words];
	//string* pwords[max_words];
	//cout << endl << "Enter a string terminated by #:" << endl;
	//getline(cin,text,'#');
	////cout << text << endl;
	//int start=text.find_first_not_of(separators);
	//int end=0;
	//int word_count=0;
	//while(start != string::npos && word_count < max_words){
	//	end=text.find_first_of(separators,start+1);
	//	if(end == string::npos){
	//		end=text.length();
	//	}
	//	words[word_count]=text.substr(start,end-start);
	//	pwords[word_count]=&words[word_count];
	//	//cout << words[word_count] << endl;
	//	word_count++;
	//	start=text.find_first_not_of(separators,end+1);
	//}
	//int lowest=0;
	//for(int j = 0;j < word_count - 1; j++){
	//	lowest=j;
	//	for(int i=j+1;i < word_count; i++){
	//		if(*pwords[i] < *pwords[lowest]){
	//			lowest=i;
	//		}
	//		if(lowest != j){
	//			string* ptemp=pwords[j];
	//			pwords[j]=pwords[lowest];
	//			pwords[lowest]=ptemp;
	//		}
	//	}
	//}
	//cout << "指针间接运算符输出:" << endl;
	//for(int i=0; i < word_count ;i++){
	//	cout << endl << *pwords[i];
	//}
	//cout << "数组输出:" <<endl;
	//for(int i=0; i < word_count ;i++){
	//	cout << endl << words[i];
	//}
	
	

	/*string str1="and";
	string str2="taxes";
	cout << (str1 > str2) << endl;
	return 0;*/

	//const int num1=10;
	//int num2=20;
	//const int* const pnum=&num1;
	////*pnum=15;   //wrong 不能给常量赋值
	//cout << *pnum << endl;
	////pnum=&num2;
	//cout << *pnum << endl;

	//常量指针(指向常量的指针) 指针指向的内容不能修改,但可以把指针设置为指向其他的内容
	/*int value=20;
	const int value1=30;
	const int* pvalue=&value;
	cout << *pvalue << endl;*/

	//指针常量. 存储在指针中的地址不能修改 (始终指向初始化时指定的地址,地址的内容不是常量，可以修改
	/*//int value=20;
	//int value1=30;
	//int* const pvalue=&value;
	//cout << *pvalue << endl;
	////pvalue=&value1;	//wrong 初始化地址后不能在修改
	//cout << *pvalue << endl;
	//cout << value << endl;*/



	/*int num[2]={1,2};
	int* pnum=num;
	cout << pnum << endl;
	cout << *pnum << endl;
	cout << *(pnum+1) << endl;
	cout << *(pnum+2) << endl;*/

	//int count=0;
	//cout << "请输入数组的大小:" << endl;
	//cin >> count;
	//float* pnum=new float[count];
	////index n :1.0/(n+1)2次方
	//for(int i=0; i<count; i++){
	//	*(pnum+i)=1.0 / pow(static_cast<float>(i+1),2);
	//}
	//cout << "数据的各个元素:" << endl;
	//for(int i=0; i<count; i++){
	//	cout << "第" << i << "个数:" << *(pnum+i) << endl;
	//}
	//float sum=0.0;
	//for(int i=0; i<count; i++){
	//	sum+=*(pnum+i);
	//}
	//cout << "sum="
	//	 << sum 
	//	 << endl
	//	 << "sum*6="
	//	 << (sum*6)
	//	 << endl
	//	 << " pow(sum,2)="
	//	 << pow(sum,2)
	//	 << endl;
	//delete pnum;

	//int arraycount=3;
	//int numcount=6;
	//int** pnum=new int*[arraycount];
	//for(int i=0; i<arraycount; i++){
	//	pnum[i]=new int[numcount];	//or *(pnum+i)=new int[numcount];
	//	for(int j=0; j<numcount; j++){
	//		switch(i){
	//		case 0:
	//			*(pnum[i]+j)=j+1;  //or *(*(pnum+i)+j)=j+1;
	//			break;
	//		case 1:
	//			*(*(pnum+i)+j)=pow(static_cast<double>(j+1),2);
	//			break;
	//		case 2:
	//			*(*(pnum+i)+j)=pow(static_cast<double>(j+1),3);
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//}
	//for(int i=0; i<arraycount; i++){
	//	for(int j=0; j<numcount; j++){
	//		cout << *(*(pnum+i)+j)
	//			 << ", ";
	//	}
	//	cout << endl;
	//}
	//for(int i=0; i<arraycount; i++){
	//	delete *(pnum+i); //or delete pnum[i];
	//}
	//delete [] pnum;

	/*cout << endl;
	for(int i=-3; i<=3; i++){
		cout << setw(10) << power(8.0,i);
	}*/
	//value_input(55,100);

	/*string str;
	cout << "请输入字符串" << endl;
	cin >> str;
	cout << "输入的字符串:" << endl << str << endl;
	char* ch= reversalStr(str.c_str());
	cout << "反转后字符串_0:" << endl;
	for(int i=0; i<strlen(ch); i++){
		cout << ch[i];
	}
	cout << endl << "反转后字符串_1:" << endl;
	cout << ch << endl;

	int a=1;
	cout << "输出:" << endl;
	cout << do_it(a);*/
	
	/*int a=3;
	int b=2;
	cout << larger(a,b) << endl;
	cout << larger(1.5,2.5) << endl;
	cout << *larger(&a,&b) << endl;*/

	//输入一串文本，排序单词
	/*string text;
	const string separators=" ,.\"\n";
	cout << endl << "Enter a string terminated by #:" << endl;
	getline(cin,text,'#');
	int word_count=count_words(text,separators);
	cout << "单词个数为:" << word_count << endl;
	if(0 == word_count){
		cout << endl << "No words in text." << endl;
	}
	string** pWords=new string*[word_count];
	extract_words(pWords,text,separators);
	sort(pWords,0,word_count-1);
	show_words(pWords,word_count);
	for(int i=0;i<word_count;i++){
		delete pWords[i];
	}
	delete[] pWords;*/

	//cout << "3.4,2.5=" << (plus(3.4,2.5)) << endl;
	//cout << "1,2=" << (plus(1,2)) << endl;
	////cout << "1,2.1" << (plus(1,2.1)) << endl;
	////cout << "he,llo=" << (plus("he","llo")) << endl;  //不能相加两个指针
	//string str1="he";
	//string str2="llo";
	//cout << "he,llo=" << (plus(str1,str2)) << endl;
     

	/*extern const double pi;
	cout << "pi=" << data::pi << endl;*/

	/*for (int i = 0; i < argc; i++)
	{
		cout << endl << argv[i];
	}
	cout << endl;*/

	//测试命名空间
	/*cout << data::pi << endl;
	cout << data::pii << endl;
	cout << data::days[1] << endl;*/

	/*double date[] ={1.5,4.6,3.1,1.1,3.8,2.1};
	const int datesize=sizeof(date)/sizeof(date[0]);
	cout << endl;
	cout << "Minimum double is " << compare::min(date,datesize) << endl;
	cout << "Maxinum double is " << compare::max(date,datesize) << endl;*/

	/*int a=10,b=5;
	int result=0;
	int (*pfun[])(int,int)={fun::sum,};
	int fcount =sizeof(pfun)/sizeof(pfun[0]);
	int select=0;
	result=pfun[0](a,b);
	cout << "result=" << result << endl;
	assert(result<10);*/
	value_input(1,2);
	
}
double compare::max(const double* date,int size){
	double result=date[0];
	for (int i = 1; i < size; i++){
		if(result<date[i]){
			result=date[i];
		}
	}
	return result;
}
double compare::min(const double* date,int size){
	double result=date[0];
	for (int i = 1; i < size; i++){
		if(result>date[i]){
			result=date[i];
		}
	}
	return result;
}

template <class T> T plus(T a,T b){
	T sum=a + b;
	return sum;
}
//template <> string plus<string>(string str1,string str2){
//	return str1+str2;
//}
void sort(string* pstr[],int start,int end){
	int pivotpos;
	if(start<end){
		//pstr[pivotpos]大于左边的元素小于右边的元素
		pivotpos=Partition(pstr,start,end);
		sort(pstr,start,pivotpos-1);
		sort(pstr,pivotpos+1,end);
	}
}

 int Partition(string* pstr[],int start,int end) {
	 int maxIndex=end+1;	
	 string pivot=*pstr[start];//设置轴心元素
	//从区间两端交替向中间扫描，直至i=j为止 
	while(start<end){
		// 从右向左找第一个小于x的数
		//当末尾的元素大于轴心元素值时，不做处理，让尾指针往前跳
		if(start<end && *pstr[end]>=pivot){
			end--;
		}
		swap(pstr,start,end);
		////测试输出
		//cout << "end:" << end << endl;
		//for (int i = 0; i < maxIndex; i++)
		//{
		//	cout << *(*(pstr+i)) << ",";
		//}
		//cout << endl;
		// 从左向右找第一个大于x的数
		//当前端的元素小于轴心元素时，不对元素做任何处理，让头指针往尾部跳
		if(start<end && *pstr[start]<=pivot){
			start++;
		}
		swap(pstr,start,end);
		////测试输出
		//cout << "start:" << start << endl;
		//for (int i = 0; i < maxIndex; i++)
		//{
		//	cout << *(*(pstr+i)) << ",";
		//}
		//cout << endl;
	}
	/*cout << "start:" << start << endl;
	cout << *pstr[start] << endl;*/
	return start;

 }

void swap(string* pstr[],int first,int second){
	string* temp=pstr[first];
	pstr[first]=pstr[second];
	pstr[second]=temp;
}
//计算文本单词总数
int count_words(const string& text,const string& separators){
	int start=text.find_first_not_of(separators);
	int end=0;
	int word_count=0;
	while(start != string::npos){
		end=text.find_first_of(separators,start+1);
		if(end == string::npos){
			end=text.length();
		}
		word_count++;
		start=text.find_first_not_of(separators,end+1);
	}
	return word_count;
}
//提取单词
void extract_words(string* pstr[],const string& text,const string& separators){
	int start=text.find_first_not_of(separators);
	int end=0;
	int word_count=0;
	while(start != string::npos){
		end=text.find_first_of(separators,start+1);
		if(end == string::npos){
			end=text.length();
		}
		pstr[word_count++]=new string(text.substr(start,end-start));
		start=text.find_first_not_of(separators,end+1);
	}
}
//输出单词
void show_words(string* pstr[],int count){
	for(int i=0;i<count;i++){
		cout << " " << *pstr[i] << endl;
	}
}

template <class T> T larger(T a,T b){
	return a>b?a:b;
}

int& do_it(int& num){
	num++;
	return num;
}

char* reversalStr(const char* ch){
	 int len= strlen(ch);
	 char* temp=new char[len];
	 strcpy(temp,ch);
	 //1:数组
	/* for(int i=0; i<len/2; i++){
		char c=temp[i];
		temp[i]=temp[len-i-1];
		temp[len-i-1]=c;
	 }
	 return temp;*/
	 //2:指针
	 /*char* ret=temp;
	 char* retLast=temp+len-1;
	 while(retLast>temp){
		 char c=*temp;
		 *temp++=*retLast;
		 *retLast--=c;
	 }
	 return ret;*/
	 //3:移位对换
	 char* ret=temp;
	 char* retlast=temp+len-1;
	 while(retlast>temp){
		 *retlast ^=  *temp;
		 *temp ^=  *retlast;
		 *retlast-- ^=  *temp++;
	 }
	 return ret;
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

double power(double x,int n){
	double result=1.0;
	if(n>=0){
		for(int i=0; i<n; i++){
			result *=x;
		}
	}
	else{
		for(int i=0; i<-n; i++){
			result /=x;
		}
	}
	return result;
}