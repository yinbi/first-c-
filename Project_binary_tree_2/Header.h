#pragma once
#include<iostream>
using namespace std;
#define Maxsize 100
//��������Ԫ������
//*********int check = 0;//��Ϊ�жϱ��ʽ�Ƿ���ȷ�ı��
typedef char  elemtype;
//������������ݱ���
typedef union
{
	char Operator;
	double date;
}perdate;
//�����������ʽ�洢�ṹ
typedef struct node
{
	perdate DATE;//��union���ʹ�������������
	struct node *lchild;
	struct node *rchild;
}btnode;
//�������������Ľṹ����
struct op
{
	char opration;
	int index;//���Ų���//�����index�����Ϊ-1ʱ���Ͳ����ٴα����ҵ�
	int locate;//op��λ��
};
extern int index;
extern struct op Aop[Maxsize];
//******************************************************
//����op�������Aop����
int Sortop(char str[], op Aop[], int &index);
//���ַ���ת��Ϊ������
double str_to_flaot(char strpoly[], int p, int q);
//�ж������ǲ���1.2���ͣ�����ֻ������
bool isdate(char str[], int p, int q);//p,qָ��str�Ŀ�ʼ�ͽ�β��
//�ж�str�Ƿ�Ϊ�����������
bool isoprater(char str[], int p, int q);//p,qָ��str�Ŀ�ʼ�ͽ�β��
//���������ʽ����������
void Createbtnode(btnode *b, char *str, int p, int q, int tail);//p,qָ��str�Ŀ�ʼ�ͽ�β����tail��Aop��βָ��
//�����������ʽ�Ľ��
double Comp(btnode *b);