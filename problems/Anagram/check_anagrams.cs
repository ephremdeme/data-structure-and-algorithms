using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class check_anagrams
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter two strings in two different lines: ");
            string a = Console.ReadLine();
            string b = Console.ReadLine();
            int[] a_frequency = new int[256];
            int[] b_frequency = new int[256];
            bool isAnagram = true;
            foreach (char c in a)
            {
                a_frequency[(int)c]++;
            }
            foreach (char c in b)
            {
                b_frequency[(int)c]++;
            }
            for(int i = 0; i < 256; i++)
            {
                if(a_frequency[i] != b_frequency[i])
                {
                    isAnagram = false;
                    break;
                }
            }
            if (isAnagram)
            {
                Console.WriteLine(a + " and " + b + " are anagrams.");
            }
            else
            {
                Console.WriteLine(a + " and " + b + " are NOT anagrams.");
            }
        }
    }
}
