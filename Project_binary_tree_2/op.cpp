#include"Header.h"
//查找op，并填充Aop数组
int Sortop(char str[], op Aop[], int &index)
{
	int j = 0;//记录Aop的top
	int i;
	int ind = 0;//记录括号层数
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			ind++;
		else if (str[i] == ')')
			ind--;
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			Aop[j].opration = str[i];
			Aop[j].index = ind;
			Aop[j].locate = i;
			j++;
		}
		index = (index > ind) ? index : ind;
	}
	return j;
}
//将字符串转化为浮点数
double str_to_flaot(char strpoly[], int p, int q)
{
	if (strpoly[p] == '(')
		p++;
	if (strpoly[q] == ')')
		q--;
	//判断小数点前有几位数字
	int index = 0;
	int temp = p;//保存原来的p值
	double  n = 0;//最后的浮点数
	for (; (p <= q) && (strpoly[p] != '.'); p++) index++;
	p = temp;
	for (; p <= q; p++)
	{
		if (strpoly[p] == '.')  continue;
		index--;
		n = n + ((double)(strpoly[p] - '0'))*(pow(10, index));

	}
	return n;
}
//判断数组是不是1.2类型，就是只有数据//忽略括号
bool isdate(char str[], int p, int q)
{
	int i;
	int index = 0;
	for (i = p; i <= q; i++)
	{
		if (str[i] == '.')
			index++;
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
			return false;
	}
	if (index == 0 || index == 1)
	{
		return true;
	}
	else
		abort();
}
//判断str是否为运算符和括号
bool isoprater(char str[], int p, int q)
{
	if ((p == q) && (str[p] == '(' || str[p] == ')' || str[p] == '*' || str[p] == '/' || str[p] == '^' || str[p] == '+' || str[p] == '-'))
		return true;
	else
		return false;
}
//用算数表达式创建二叉树
void Createbtnode(btnode *b, char *str, int p, int q, int tail)        //由str串创建二叉链
{                                                            //p,q分别标志Aop的首尾
	int i = 0;
	int j = 0;//
	int find = 0;
	if (isdate(str, p, q))//str为1.3类型
	{
		//创建头节点，并将数据位置为str_to_double
		b->DATE.date = str_to_flaot(str, p, q);
		b->lchild = NULL;
		b->rchild = NULL;
	}
	else if (isoprater(str, p, q))//str为+、—、^、（、）、*
	{
		abort();
		b->DATE.Operator = str[i];
		b->lchild = NULL;
		b->rchild = NULL;
	}
	///***************************************************************
	else
		for (int temp = 0; temp <= index; temp++)
		{
		for (j = tail; j >= 0; j--)//从后往前找，才符合运算的法则，前面先算后面后算
		{
			if (Aop[j].index == temp && ((Aop[j].opration == '+') || (Aop[j].opration == '-')) && Aop[j].locate >= p&&Aop[j].locate <= q)
			{
				find++;
				Aop[j].index = -1;//标志这个已经被找过了
				btnode *lt, *rt;
				lt = new btnode;
				rt = new btnode;
				b->lchild = lt;
				b->rchild = rt;
				b->DATE.Operator = Aop[j].opration;
				Createbtnode(b->lchild, str, p, Aop[j].locate - 1, tail);
				Createbtnode(b->rchild, str, Aop[j].locate + 1, q, tail);
			}
		}
		if (find == 0)
			for (j = tail; j >= 0; j--)
			{
			if (Aop[j].index == temp && ((Aop[j].opration == '*') || (Aop[j].opration == '/')) && Aop[j].locate >= p&&Aop[j].locate <= q)
			{
				find++;
				Aop[j].index = -1;//标志这个已经被找过了
				btnode *lt, *rt;
				lt = new btnode;
				rt = new btnode;
				b->lchild = lt;
				b->rchild = rt;
				b->DATE.Operator = Aop[j].opration;
				Createbtnode(b->lchild, str, p, Aop[j].locate - 1, tail);
				Createbtnode(b->rchild, str, Aop[j].locate + 1, q, tail);
			}
			}
		if (find == 0)
			for (j = tail; j >= 0; j--)
			{
			if (Aop[j].index == temp && (Aop[j].opration == '^') && Aop[j].locate >= p&&Aop[j].locate <= q)
			{
				Aop[j].index = -1;//标志这个已经被找过了
				btnode *lt, *rt;
				lt = new btnode;
				rt = new btnode;
				b->lchild = lt;
				b->rchild = rt;
				b->DATE.Operator = Aop[j].opration;
				Createbtnode(b->lchild, str, p, Aop[j].locate - 1, tail);
				Createbtnode(b->rchild, str, Aop[j].locate + 1, q, tail);
			}
			}
		}
}
//计算二叉树算式的结果
double Comp(btnode *b)
{
	double v1, v2;
	if (b == NULL) return 0;
	if (b->lchild == NULL && b->rchild == NULL)
		return b->DATE.date;    //叶子节点直接返回节点值
	v1 = Comp(b->lchild);
	v2 = Comp(b->rchild);
	switch (b->DATE.Operator)
	{
	case '+':
		return v1 + v2;
	case '-':
		return v1 - v2;
	case '*':
		return v1*v2;
	case '/':
		if (v2 != 0)
			return v1 / v2;
		else
			abort();
	case '^':
		return (pow(v1, v2));
	default:
		abort();
	}
}