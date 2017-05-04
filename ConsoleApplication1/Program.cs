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

            DateTime dt = Convert.ToDateTime("2014-02-02");
            Console.WriteLine((int)DateTime.Now.AddDays(4).DayOfWeek);
            Console.ReadKey();
        }

        
    }
}
