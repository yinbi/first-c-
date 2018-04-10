//https://blog.csdn.net/chenht8/article/details/53208914
#include <iostream>
#include <list>
#include <sstream>
#include <iomanip>
using namespace std;

struct Token {  // 一个简单的结构体，成员只有一个字符串，用来储存数值或符号
	string text;
	Token(string text) : text(text) {}
	double doubleValue() {  // 将string类型转化为double类型
		stringstream ss(text);
		double value;
		ss >> value;
		return value;
	}
};

class Parser {

	struct Tree {      // 二叉树
		Token token;   // 储存数值或符号
		Tree * left;   // 指向左子树的指针
		Tree * right;  // 指向右子树的指针

		Tree(Token token) : token(token) {
			left = 0;
			right = 0;
		}
		~Tree() {
			if (left != 0) delete left;
			if (right != 0) delete right;
		}
	};

	Tree * expression;  // 指向表达式二叉树的指针
	double result;      // 整个表达式的计算结果

	static double execute(Tree * expression) {  // 计算表达式的值
		if (expression->left == 0) {   // 左子树为空时，token储存的是当前子树的值
			return expression->token.doubleValue();
		}
		else {   // 左右子树均存在，分别计算左右子树的值，再根据符号进行四则运算
			double left = execute(expression->left);
			double right = execute(expression->right);
			switch (expression->token.text[0]) { // 左右子树均存在时，token储存的是符号
			case '+': return left + right;
			case '-': return left - right;
			case '*': return left * right;
			case '/': return left / right;
			}
			// 这里不加的话会报warning: control may reach end of non-void function
			return 0;
		}
	}

public:
	Parser() {
		expression = 0;
	}

	~Parser() {
		if (expression != 0) delete expression;
	}

	// 执行表达式计算
	double execute() {
		if (expression != 0) {
			result = execute(expression);
			delete expression;
			expression = 0;
		}
		return result;
	}

	// 创建一棵新树, 这里用list模拟实现栈的功能
	void create(list<Tree*> &subTreeStack, list<string> &operatorStack) {
		Tree* node = new Tree(Token(operatorStack.back()));  // 新子树值为此时符号栈的顶部
		operatorStack.pop_back();              // pop掉符号栈的栈顶
		node->right = subTreeStack.back();     // 新树的右孩子为子树栈的顶部
		subTreeStack.pop_back();               // pop掉子树栈的栈顶
		if (!subTreeStack.empty()) {
			node->left = subTreeStack.back();  // 新树的左孩子为此时子树栈的顶部
			subTreeStack.pop_back();
		}
		else {  // 考虑特殊情况: -5、-0、+0 
			Tree* temp = new Tree(Token("0"));
			node->left = temp;                 // 新树的左孩子为一个值为0的子树
		}
		subTreeStack.push_back(node);   // 新树加进栈顶
	}

	// 将表达式构建成一棵二叉树
	void parse(string str) {
		list<Tree*> subTreeStack;    // 子树栈
		list<string> operatorStack;  // 符号栈

		for (unsigned i = 0; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {  // 数字则为叶子节点
				string value = "";
				for (unsigned j = i; j < str.length(); j++) {  // 提取数字，包含可能存在的小数点
					if ((str[j] >= '0' && str[j] <= '9') || str[j] == '.') {
						value += str[j];
						i = j;
					}
					else {
						break;
					}
				}
				Tree* node = new Tree(Token(value));
				subTreeStack.push_back(node);
			}
			else if (str[i] == '+' || str[i] == '-') {
				string value = "";
				value += str[i];
				if (operatorStack.empty()) {
					operatorStack.push_back(value);
				}
				else {
					if (i >= 1 && str[i - 1] == '(') // 当出现(- 或者(+ 手动添加一个值为0的子树
						subTreeStack.push_back(new Tree(Token("0")));
					// 遇到加减符号，如果符号栈不为空，先将此时的栈构建一棵子树，再将该符号入栈
					while (!operatorStack.empty() &&
						(operatorStack.back() == "+" || operatorStack.back() == "-"
						|| operatorStack.back() == "*" || operatorStack.back() == "/")) {
						create(subTreeStack, operatorStack);
					}
					operatorStack.push_back(value);
				}
			}
			else if (str[i] == '*' || str[i] == '/') {
				string value = "";
				value += str[i];
				if (operatorStack.empty()) {
					operatorStack.push_back(value);
				}
				else {
					// 遇到乘除符号，如果符号栈不为空且栈顶同为乘除符号，先将此时的栈构建一棵子树，再入栈
					while (!operatorStack.empty() &&
						(operatorStack.back() == "*" || operatorStack.back() == "/")) {
						create(subTreeStack, operatorStack);
					}
					operatorStack.push_back(value);
				}
			}
			else if (str[i] == '(') {
				string value = "";
				value += str[i];
				operatorStack.push_back(value);
			}
			else if (str[i] == ')') {
				while (operatorStack.back() != "(") {  // 构建子树，直至遇到 '(' 
					create(subTreeStack, operatorStack);
				}
				operatorStack.pop_back();  // pop '('
			}
		}

		while (!operatorStack.empty()) {  // 继续构建二叉树，直至符号栈为空
			create(subTreeStack, operatorStack);
		}
		expression = subTreeStack.back(); // 最后子树栈的栈顶的值即为表达式的值
	}
};

int main(int argc, char const *argv[]) {
	Parser p = Parser();
	string expression;
	while (cin >> expression) {
		if (expression.length() > 0) {  // 不处理空字符串
			p.parse(expression);
			cout << fixed << setprecision(3) << p.execute() << endl;
		}
	}
	return 0;
}