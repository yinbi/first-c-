//https://www.cnblogs.com/ruxiaobai/p/5075526.html

#include"Header.h"
int index = 0;//记录最大的括号层数
struct op Aop[Maxsize];
int main()
{
	btnode * b;
	b = new btnode;
	char str[Maxsize];
	cout << "算式计算器" << endl;
	while (true)
	{
		cout << "[Type \"exit\" to exit]" << endl << "请输入你要求的表达式：" << endl;
		cin.getline(str, Maxsize);
		if (strcmp("exit", str) == 0)  break;//如果输入的是exit则退出
		else
		{
			int tail = Sortop(str, Aop, index);//整理得到Aop的结构数组
			Createbtnode(b, str, 0, strlen(str) - 1, tail);
			double result = Comp(b);
			cout << result << endl;
		}
	}
}