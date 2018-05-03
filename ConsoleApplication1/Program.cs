using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            #region
            //string writestr = "n";
            //do
            //{
            //    Console.WriteLine("do you want leve? y/n\n");
            //    writestr = Console.ReadLine();
            //} while (writestr != "y");
            //int[] num =new int[]{ 1, 2, 3, 4, 5 };
            //for (int i = 0; i < num.Length; i++)
            //{
            //    Console.WriteLine(string.Format("第{0}个数：{1}", i + 1, num[i]));
            //}

            //for (int i = 0; i < num.Length-1; i++)
            //{
            //    for (int j = 0; j < num.Length-1-i; j++)
            //    {
            //        if (num[j] < num[j + 1])
            //        {
            //            int temp = num[j];
            //            num[j] = num[j + 1];
            //            num[j + 1] = temp;
            //        }
            //    }
            //}
            //Console.WriteLine("排序后输出");
            //for (int i = 0; i < num.Length; i++)
            //{
            //    Console.WriteLine(string.Format("第{0}个数：{1}", i + 1, num[i]));
            //}
            #endregion

            #region
            //DateTime dt = Convert.ToDateTime("2014-02-02");
            //Console.WriteLine((int)DateTime.Now.AddDays(4).DayOfWeek);
            //Console.ReadKey();
            //string exp="1+2*3-4/5";
            //string exp = "1+((2+3)*4)-5";
            //ExpresstionClass str = new ExpresstionClass(exp);
            //Console.WriteLine(str.ExpValue().ToString());
            #endregion

            //Stack
            //Console.WriteLine("[计算器]");
            //string exp = "";
            //while (exp != "exit")
            //{
            //    Console.WriteLine("请输入计算的表达式:");
            //    exp = Console.ReadLine();
            //    FourOperationsByStack fourOp = new FourOperationsByStack(exp);
            //    Console.WriteLine(fourOp.ExpValue());
            //}

            //BinaryTree
            Console.WriteLine("[计算器]");
            string exp = "";
            while (exp != "exit")
            {
                Console.WriteLine("请输入计算的表达式:");
                exp = Console.ReadLine();

                Tree tree = new Tree();
                FourOperationsByBinaryTree fourOperations = new FourOperationsByBinaryTree(exp);
                int tail = fourOperations.ToOpArrayList();// Sortop(str, Aop, index);//整理得到Aop的结构数组

                fourOperations.CreateTree(tree, 0, exp.Length - 1, tail);
                double result = fourOperations.Comp(tree);
                Console.WriteLine(result);
            }

        }
    }
}