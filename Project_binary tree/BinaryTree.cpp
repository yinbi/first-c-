//https://blog.csdn.net/chenht8/article/details/53208914
#include <iostream>
#include <list>
#include <sstream>
#include <iomanip>
using namespace std;

struct Token {  // һ���򵥵Ľṹ�壬��Աֻ��һ���ַ���������������ֵ�����
	string text;
	Token(string text) : text(text) {}
	double doubleValue() {  // ��string����ת��Ϊdouble����
		stringstream ss(text);
		double value;
		ss >> value;
		return value;
	}
};

class Parser {

	struct Tree {      // ������
		Token token;   // ������ֵ�����
		Tree * left;   // ָ����������ָ��
		Tree * right;  // ָ����������ָ��

		Tree(Token token) : token(token) {
			left = 0;
			right = 0;
		}
		~Tree() {
			if (left != 0) delete left;
			if (right != 0) delete right;
		}
	};

	Tree * expression;  // ָ����ʽ��������ָ��
	double result;      // �������ʽ�ļ�����

	static double execute(Tree * expression) {  // ������ʽ��ֵ
		if (expression->left == 0) {   // ������Ϊ��ʱ��token������ǵ�ǰ������ֵ
			return expression->token.doubleValue();
		}
		else {   // �������������ڣ��ֱ��������������ֵ���ٸ��ݷ��Ž�����������
			double left = execute(expression->left);
			double right = execute(expression->right);
			switch (expression->token.text[0]) { // ��������������ʱ��token������Ƿ���
			case '+': return left + right;
			case '-': return left - right;
			case '*': return left * right;
			case '/': return left / right;
			}
			// ���ﲻ�ӵĻ��ᱨwarning: control may reach end of non-void function
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

	// ִ�б��ʽ����
	double execute() {
		if (expression != 0) {
			result = execute(expression);
			delete expression;
			expression = 0;
		}
		return result;
	}

	// ����һ������, ������listģ��ʵ��ջ�Ĺ���
	void create(list<Tree*> &subTreeStack, list<string> &operatorStack) {
		Tree* node = new Tree(Token(operatorStack.back()));  // ������ֵΪ��ʱ����ջ�Ķ���
		operatorStack.pop_back();              // pop������ջ��ջ��
		node->right = subTreeStack.back();     // �������Һ���Ϊ����ջ�Ķ���
		subTreeStack.pop_back();               // pop������ջ��ջ��
		if (!subTreeStack.empty()) {
			node->left = subTreeStack.back();  // ����������Ϊ��ʱ����ջ�Ķ���
			subTreeStack.pop_back();
		}
		else {  // �����������: -5��-0��+0 
			Tree* temp = new Tree(Token("0"));
			node->left = temp;                 // ����������Ϊһ��ֵΪ0������
		}
		subTreeStack.push_back(node);   // �����ӽ�ջ��
	}

	// �����ʽ������һ�ö�����
	void parse(string str) {
		list<Tree*> subTreeStack;    // ����ջ
		list<string> operatorStack;  // ����ջ

		for (unsigned i = 0; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {  // ������ΪҶ�ӽڵ�
				string value = "";
				for (unsigned j = i; j < str.length(); j++) {  // ��ȡ���֣��������ܴ��ڵ�С����
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
					if (i >= 1 && str[i - 1] == '(') // ������(- ����(+ �ֶ����һ��ֵΪ0������
						subTreeStack.push_back(new Tree(Token("0")));
					// �����Ӽ����ţ��������ջ��Ϊ�գ��Ƚ���ʱ��ջ����һ���������ٽ��÷�����ջ
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
					// �����˳����ţ��������ջ��Ϊ����ջ��ͬΪ�˳����ţ��Ƚ���ʱ��ջ����һ������������ջ
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
				while (operatorStack.back() != "(") {  // ����������ֱ������ '(' 
					create(subTreeStack, operatorStack);
				}
				operatorStack.pop_back();  // pop '('
			}
		}

		while (!operatorStack.empty()) {  // ����������������ֱ������ջΪ��
			create(subTreeStack, operatorStack);
		}
		expression = subTreeStack.back(); // �������ջ��ջ����ֵ��Ϊ���ʽ��ֵ
	}
};

int main(int argc, char const *argv[]) {
	Parser p = Parser();
	string expression;
	while (cin >> expression) {
		if (expression.length() > 0) {  // ��������ַ���
			p.parse(expression);
			cout << fixed << setprecision(3) << p.execute() << endl;
		}
	}
	return 0;
}