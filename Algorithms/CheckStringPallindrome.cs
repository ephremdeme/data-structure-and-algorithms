/*
 * Checks if the entered string is a pallindrome or not.
 */


using System;
using System.Collections.Generic;

namespace DSA
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<char, int> characterPairs = new Dictionary<char, int>();
            string input = Console.ReadLine();

            foreach (char c in input)
            {
                if (characterPairs.ContainsKey(c))
                    characterPairs[c]++;
                else
                    characterPairs[c] = 1;
            }

            int oddPairs = 0;
            foreach (KeyValuePair<char, int> kvp in characterPairs)
            {
                
                if (characterPairs[kvp.Key] % 2 != 0)
                    oddPairs++;
            }
            if (oddPairs > 1)
                Console.WriteLine("The string CANNOT be rearranged to a pallindrome");
            else
                Console.WriteLine("The string CAN be rearranged to a pallindrome");
        }
    }
}
