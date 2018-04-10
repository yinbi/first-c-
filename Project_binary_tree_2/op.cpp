#include"Header.h"
//����op�������Aop����
int Sortop(char str[], op Aop[], int &index)
{
	int j = 0;//��¼Aop��top
	int i;
	int ind = 0;//��¼���Ų���
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
//���ַ���ת��Ϊ������
double str_to_flaot(char strpoly[], int p, int q)
{
	if (strpoly[p] == '(')
		p++;
	if (strpoly[q] == ')')
		q--;
	//�ж�С����ǰ�м�λ����
	int index = 0;
	int temp = p;//����ԭ����pֵ
	double  n = 0;//���ĸ�����
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
//�ж������ǲ���1.2���ͣ�����ֻ������//��������
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
//�ж�str�Ƿ�Ϊ�����������
bool isoprater(char str[], int p, int q)
{
	if ((p == q) && (str[p] == '(' || str[p] == ')' || str[p] == '*' || str[p] == '/' || str[p] == '^' || str[p] == '+' || str[p] == '-'))
		return true;
	else
		return false;
}
//���������ʽ����������
void Createbtnode(btnode *b, char *str, int p, int q, int tail)        //��str������������
{                                                            //p,q�ֱ��־Aop����β
	int i = 0;
	int j = 0;//
	int find = 0;
	if (isdate(str, p, q))//strΪ1.3����
	{
		//����ͷ�ڵ㣬��������λ��Ϊstr_to_double
		b->DATE.date = str_to_flaot(str, p, q);
		b->lchild = NULL;
		b->rchild = NULL;
	}
	else if (isoprater(str, p, q))//strΪ+������^����������*
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
		for (j = tail; j >= 0; j--)//�Ӻ���ǰ�ң��ŷ�������ķ���ǰ������������
		{
			if (Aop[j].index == temp && ((Aop[j].opration == '+') || (Aop[j].opration == '-')) && Aop[j].locate >= p&&Aop[j].locate <= q)
			{
				find++;
				Aop[j].index = -1;//��־����Ѿ����ҹ���
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
				Aop[j].index = -1;//��־����Ѿ����ҹ���
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
				Aop[j].index = -1;//��־����Ѿ����ҹ���
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
//�����������ʽ�Ľ��
double Comp(btnode *b)
{
	double v1, v2;
	if (b == NULL) return 0;
	if (b->lchild == NULL && b->rchild == NULL)
		return b->DATE.date;    //Ҷ�ӽڵ�ֱ�ӷ��ؽڵ�ֵ
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