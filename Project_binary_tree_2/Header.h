#pragma once
#include<iostream>
using namespace std;
#define Maxsize 100
//定义数据元素类型
//*********int check = 0;//作为判断表达式是否正确的标记
typedef char  elemtype;
//定义二叉树数据变量
typedef union
{
	char Operator;
	double date;
}perdate;
//定义二叉树链式存储结构
typedef struct node
{
	perdate DATE;//用union类型存运算符或操作数
	struct node *lchild;
	struct node *rchild;
}btnode;
//定义查找运算符的结构数组
struct op
{
	char opration;
	int index;//括号层数//当这个index被标记为-1时，就不会再次被查找到
	int locate;//op的位置
};
extern int index;
extern struct op Aop[Maxsize];
//******************************************************
//查找op，并填充Aop数组
int Sortop(char str[], op Aop[], int &index);
//将字符串转化为浮点数
double str_to_flaot(char strpoly[], int p, int q);
//判断数组是不是1.2类型，就是只有数据
bool isdate(char str[], int p, int q);//p,q指向str的开始和结尾处
//判断str是否为运算符和括号
bool isoprater(char str[], int p, int q);//p,q指向str的开始和结尾处
//用算数表达式创建二叉树
void Createbtnode(btnode *b, char *str, int p, int q, int tail);//p,q指向str的开始和结尾处；tail是Aop的尾指针
//计算二叉树算式的结果
double Comp(btnode *b);