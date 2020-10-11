cusing System;

namespace Fibonacci
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter limit: ");
            calculateFibonacci(Int32.Parse(Console.ReadLine()));
        }

        static void calculateFibonacci (int input)
        {
            int a = 0;
            int b = 1;

            while (b <= input)
            {
                int auxiliar = a; 
                a = b; 
                b = auxiliar + a;
                Console.Write(a + " ");
            }
        }
        
    }
}