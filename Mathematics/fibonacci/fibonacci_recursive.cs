using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fibonacci_Recursive
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Put in n\nn = index of Fibonacci digits");
            int n = Convert.ToInt32(Console.ReadLine());
            int fib = Fibonacci_rec(n);

            Console.WriteLine($"\nThe {n}. fib-digit is {fib}");


            Console.ReadLine();
        }
        public static int Fibonacci_rec(int n)
        {
            if (n == 0)
                return 0;
            return n == 1 ? 1 : n == 2 ? 1 : Fibonacci_rec(n - 1) + Fibonacci_rec(n - 2);
        }
    }
}
