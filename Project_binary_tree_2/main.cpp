//https://www.cnblogs.com/ruxiaobai/p/5075526.html

#include"Header.h"
int index = 0;//��¼�������Ų���
struct op Aop[Maxsize];
int main()
{
	btnode * b;
	b = new btnode;
	char str[Maxsize];
	cout << "��ʽ������" << endl;
	while (true)
	{
		cout << "[Type \"exit\" to exit]" << endl << "��������Ҫ��ı��ʽ��" << endl;
		cin.getline(str, Maxsize);
		if (strcmp("exit", str) == 0)  break;//����������exit���˳�
		else
		{
			int tail = Sortop(str, Aop, index);//����õ�Aop�Ľṹ����
			Createbtnode(b, str, 0, strlen(str) - 1, tail);
			double result = Comp(b);
			cout << result << endl;
		}
	}
}