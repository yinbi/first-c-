using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public class FourOperationsByStack
    {
        public string expression;
        public FourOperationsByStack()
        {

        }
        public FourOperationsByStack(string expression)
        {
            this.expression = expression;
        }
        // 判断字符串是否为数值
        public bool IsNumberExp(string str)
        {
            bool isnumeric = false;
            byte c;
            if (str == null || str.Length == 0)
                return false;
            System.Text.ASCIIEncoding ascii = new System.Text.ASCIIEncoding();
            byte[] bytestr = ascii.GetBytes(str);
            for (int i = 0; i < bytestr.Length; i++)
            {
                c = bytestr[i];
                if ((c >= 48 && c <= 57) || c == 46)
                {
                    isnumeric = true; ;
                }
                else
                {
                    if (c == 45 && bytestr.Length > 1)
                    {
                        isnumeric = true;
                    }
                    else
                    {
                        isnumeric = false;
                        break;
                    }
                }
            }
            return isnumeric;
        }

        //提取数字与操作符
        public ArrayList ToArrayListForExp(string expression)
        {
            ArrayList exp_arraylist = new ArrayList();
            string exp_element = "", expchar = "";
            for (int i = 0; i < expression.Length; i++)
            {
                expchar = expression.Substring(i, 1);
                if (char.IsNumber(expression, i) || expchar == "." || (expchar == "-" && (i == 0 || expression.Substring(i - 1, 1) == "(")))
                {
                    exp_element += expchar;
                }
                else
                {
                    if (exp_element != "")
                    {
                        exp_arraylist.Add(exp_element);
                    }
                    exp_arraylist.Add(expchar);
                    exp_element = "";
                }
            }

            if (exp_element != "")
            {
                exp_arraylist.Add(exp_element);
            }
            return exp_arraylist;
        }
        private int Operatororder(string op)
        {
            switch (op)
            {
                case "*":
                    return 4;
                    break;
                case "/":
                    return 4;
                    break;
                case "+":
                    return 2;
                    break;
                case "-":
                    return 2;
                    break;
                default:
                    return 0;
                    break;
            }
        }

        //如果待压栈的操作符比栈顶操作符优先级高，则直接压栈，否则将S1中的栈顶元素出栈，并压入S2中
        private bool IsPop(string op, Stack operators)
        {
            if (operators.Count == 0)
            {
                return false;
            }
            else
            {
                //如果运算优先级高返回false,否则返回true
                if (operators.Peek() == ")" || Operatororder(op) > Operatororder(operators.Peek().ToString()))
                {
                    return false;
                }
                else
                {
                    //待压栈操作符优先级低于栈顶元素
                    return true;
                }
            }
        }


        public ArrayList ToExpBack_ArrayList(ArrayList exp)
        {
            ArrayList expBack_arrayList = new ArrayList();
            Stack operations = new Stack();
            string op;
            foreach (string s in exp)
            {
                if (IsNumberExp(s))
                {
                    expBack_arrayList.Add(s);
                }
                else
                {
                    switch (s)
                    {
                        case "+":
                        case "-":
                        case "*":
                        case "/":
                            while (IsPop(s, operations))
                            {
                                expBack_arrayList.Add(operations.Pop());
                            }
                            operations.Push(s);
                            break;
                        case "(":
                            operations.Push(s);
                            break;
                        case ")":
                            //如果遇到)，则依次弹出S1栈顶的运算符，并压入S2，直到遇到左括号为止，此时将这一对括号丢弃。
                            while (operations.Count != 0)
                            {
                                op = operations.Pop().ToString();
                                if (op != "(")
                                {
                                    expBack_arrayList.Add(op);
                                }
                                else
                                {
                                    break;
                                }
                            }
                            break;
                    }
                }
            }

            while (operations.Count != 0)
            {
                expBack_arrayList.Add(operations.Pop());
            }
            return expBack_arrayList;

        }
        //计算
        public double ExpValue(ArrayList expback)
        {
            double num1, num2, result = 0;
            Stack num = new Stack();
            foreach (string s in expback)
            {
                if (IsNumberExp(s))
                {
                    num.Push(s);
                }
                else
                {
                    num2 = Convert.ToDouble(num.Pop());
                    num1 = Convert.ToDouble(num.Pop());
                    result = account(num1, num2, s);
                    num.Push(result);
                }
            }
            return result;
        }
        // 基本一目计算
        public double account(double n1, double n2, string num_op)
        {
            double aresult = 0;
            switch (num_op)
            {
                case "+":
                    aresult = n1 + n2;
                    break;
                case "-":
                    aresult = n1 - n2;
                    break;
                case "*":
                    aresult = n1 * n2;
                    break;
                case "/":
                    aresult = n1 / n2;
                    break;
            }
            return aresult;
        }
        public double ExpValue()
        {
            ArrayList a1 = new ArrayList();
            ArrayList a2 = new ArrayList();

            a1 = ToArrayListForExp(expression);
            a2 = ToExpBack_ArrayList(a1);
            return ExpValue(a2);
        }
    }
}