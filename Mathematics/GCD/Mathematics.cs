using System;

namespace TestMath
{
    public static class Mathematics
    {
        /// <summary>
        ///  Calcualtes  Greatest Common Divisor of given 2 integers
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public static int GCD(int a,int b)
        {
            if (a % b == 0)
            {
                return b;
            }

            return GCD(b, a % b);
        }

        /// <summary>
        /// Calcualtes Least Common Multiple  of given 2 integers
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public static int LCM(int a, int b)
        {
            return Math.Min(a, b) * GCD(a, b);
        }
    }
}
