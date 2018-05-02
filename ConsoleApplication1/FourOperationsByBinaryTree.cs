using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    public struct node
    {
        public string Operator;
        public double date;
    }
    /// <summary>
    /// 运算符结构数组
    /// </summary>
    public struct op
    {
        public string opration;
        public int index;//括号层数//当这个index被标记为-1时，就不会再次被查找到
        public int locate;//op的位置
    };
    public class Tree
    {
       // public node DATE{get;set;}}//存储运算符或操作数
        public node DATE;
        //public Tree LTree;
        public Tree LTree { get; set; }
        //public Tree RTree;
        public Tree RTree { get; set; }
    }
    public class FourOperationsByBinaryTree
    {
        //查找op
        public ArrayList li;
        //记录最大的括号层数
        public int index = 0;
        public string expression;
        public char[] str;
        public op[] Aop;
        public FourOperationsByBinaryTree(string expression)
        {
            li = new ArrayList();
            this.expression = expression;
            this.str = expression.ToCharArray();
            Aop = new op[100];
        }
        
        public int ToOpArrayList()
        {
            int j = 0;//记录Aop的top  //ArrayList top
            //int i;
            int ind = 0;//记录括号层数
            string expchar = string.Empty;
            for (int i = 0; i < expression.Length; i++)
            {
                expchar = expression.Substring(i, 1);
                if(expchar=="(")
                {
                    ind++;
                }
                else if(expchar==")")
                {
                    ind--;
                }
                else if (expchar == "+" || expchar == "-" || expchar == "*" || expchar == "/")
                {
                    //op Aop;
                    //Aop.index = ind;
                    //Aop.opration = expchar;
                    //Aop.locate = i;
                    //li.Add(Aop);
                    Aop[j].opration = expchar;
                    Aop[j].index = ind;
                    Aop[j].locate = i;
                    j++;
                }
                index = (index > ind) ? index : ind;
            }
            return j;
        }
        //判断数组是不是1.2类型，就是只有数据//忽略括号
        bool isdate(char[] str, int p, int q)
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
            return true;//abort();
        }
        //判断str是否为运算符和括号
        bool isoprater(char[] str, int p, int q)
        {
            if ((p == q) && (str[p] == '(' || str[p] == ')' || str[p] == '*' || str[p] == '/' || str[p] == '^' || str[p] == '+' || str[p] == '-'))
                return true;
            else
                return false;
        }
        //将字符串转化为浮点数
        double str_to_float(char[] strpoly, int p, int q)
        {
            if (strpoly[p] == '(')
                p++;
            if (strpoly[q] == ')')
                q--;
            //判断小数点前有几位数字
            int index = 0;
            int temp = p;//保存原来的p值
            double n = 0;//最后的浮点数
            for (; (p <= q) && (strpoly[p] != '.'); p++) index++;
            p = temp;
            for (; p <= q; p++)
            {
                if (strpoly[p] == '.') continue;
                index--;
                n = n + ((double)(strpoly[p] - '0')) * (Math.Pow(10, index));

            }
            return n;
        }
        public void CreateTree(Tree tree, int p, int q, int tail)
        {
            int i = 0;
            //int j = 0;//
            int find = 0;

            if (isdate(str, p, q))
            {
                tree.DATE.date = str_to_float(str, p, q);
                tree.LTree = null;
                tree.RTree = null;
            }
            else if (isoprater(str, p, q))
            {
                tree.DATE.Operator = str[i].ToString();
                tree.LTree = null;
                tree.RTree = null;
            }
            else
            {
                //括号优先级高
                for (int temp = 0; temp <= index; temp++)
                {
                    //从后往前找，才符合运算的法则，前面先算后面后算
                    for (int j = tail - 1; j >= 0; j--)
                    {
                        //op Aop = (op)li[j];
                        if (Aop[j].index == temp && ((Aop[j].opration == "+") || (Aop[j].opration == "-")) && Aop[j].locate >= p && Aop[j].locate <= q)
                        {
                            find++;
                            Aop[j].index = -1;//标志这个已经被找过了
                            //li.RemoveAt(j);
                            //li.Add(Aop);
                            Tree lt = new Tree();
                            Tree rt = new Tree();
                            tree.LTree = lt;
                            tree.RTree = rt;
                            tree.DATE.Operator = Aop[j].opration;
                            Log.Write("log", string.Format("p:{0},q:{1}", p, Aop[j].locate - 1));
                            CreateTree(tree.LTree, p, Aop[j].locate - 1, tail);
                            CreateTree(tree.RTree, Aop[j].locate + 1, q, tail);
                        }
                    }
                    if (find == 0)
                    {
                        for (int j = tail - 1; j >= 0; j--)
                        {
                            if (Aop[j].index == temp && ((Aop[j].opration == "*") || (Aop[j].opration == "/")) && Aop[j].locate >= p && Aop[j].locate <= q)
                            {
                                find++;
                                Aop[j].index = -1;//标志这个已经被找过了
                                Tree lt, rt;
                                lt = new Tree();
                                rt = new Tree();
                                tree.LTree = lt;
                                tree.RTree = rt;
                                tree.DATE.Operator = Aop[j].opration;
                                CreateTree(tree.LTree, p, Aop[j].locate - 1, tail);
                                CreateTree(tree.RTree, Aop[j].locate + 1, q, tail);
                            }
                        }
                    }
                }

            }
        }

        #region
        /// <summary>
        /// 用算数表达式创建二叉树
        /// </summary>
        /// <param name="tree"></param>
        /// <param name="expression">字符串表达式</param>
        /// <param name="p">结构数组首</param>
        /// <param name="q">结构数组尾</param>
        /// <param name="tail">尾运算符索引</param>
        //public void CreateTree(Tree tree, string expression, int p, int q, int tail)
        //{
        //    int i = 0;
        //    //int j = 0;//
        //    int find = 0;
        //    int subLen = q - p;
        //    subLen = (subLen == 0 ? 1 : subLen);
        //    string exp = expression.Substring(p, subLen);
        //    int num;
        //    if (int.TryParse(exp, out num))
        //    {
        //        tree.DATE.date = num;
        //        tree.LTree = null;
        //        tree.RTree = null;
        //    }
        //    else if (exp == "+" || exp == "-")
        //    {
        //        return;
        //    }
        //    else
        //    {
        //        //括号优先级高
        //        for (int temp = 0; temp <= index; temp++)
        //        {
        //            //从后往前找，才符合运算的法则，前面先算后面后算
        //            for (int j = tail-1; j >= 0; j--)
        //            {
        //                op Aop = (op)li[j];
        //                if (Aop.index == temp && ((Aop.opration == "+") || (Aop.opration == "-")) && Aop.locate >= p && Aop.locate <= q)
        //                {
        //                    find++;
        //                    Aop.index = -1;//标志这个已经被找过了
        //                    Tree lt, rt;
        //                    lt = new Tree();
        //                    rt = new Tree();
        //                    tree.LTree = lt;
        //                    tree.RTree = rt;
        //                    tree.DATE.Operator = Aop.opration;
        //                    CreateTree(lt, expression, p, Aop.locate - 1, tail);
        //                    CreateTree(lt, expression, Aop.locate + 1, q, tail);
        //                }
        //            }
        //            if (find == 0)
        //            {
        //                for (int j = tail-1; j >= 0; j--)
        //                {
        //                    op Aop = (op)li[j];
        //                    if (Aop.index == temp && ((Aop.opration == "*") || (Aop.opration == "/")) && Aop.locate >= p && Aop.locate <= q)
        //                    {
        //                        find++;
        //                        Aop.index = -1;//标志这个已经被找过了
        //                        Tree lt, rt;
        //                        lt = new Tree();
        //                        rt = new Tree();
        //                        tree.LTree = lt;
        //                        tree.RTree = rt;
        //                        tree.DATE.Operator = Aop.opration;
        //                        CreateTree(lt, expression, p, Aop.locate - 1, tail);
        //                        CreateTree(lt, expression, Aop.locate + 1, q, tail);
        //                    }
        //                }
        //            }
        //        }

        //    }
        //}
        #endregion

        //计算二叉树算式结果
        public double Comp(Tree tree)
        {
            double v1, v2;
            if (tree == null) return 0;
            if (tree.LTree == null && tree.RTree == null)
            {
                return tree.DATE.date;
            }
            v1 = Comp(tree.LTree);
            v2 = Comp(tree.RTree);
            switch (tree.DATE.Operator)
            {
                case "+":
                    return v1 + v2;
                case "-":
                    return v1 - v2;
                case "*":
                    return v1 * v2;
                case "/":
                    return v1 / v2;
                default:
                    break;
            }
            return 0;
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
       
    }
}