using System;
using System.Collections.Generic;
using System.Linq;

namespace FirstDuplicate
{
    public static class Util
    {

        /// <summary>
        /// Returns the first duplicate from a collection.
        /// </summary>
        /// <param name="collection">List/Array of integers</param>
        /// <returns>The first duplicated element or -1.</returns>
        public static int FirstDuplicate(IEnumerable<int> collection)
        {
            List<int> seen = new List<int>();

            foreach (var n in collection)
            {
                if (seen.Contains(n))
                {
                    return n;
                }
                else
                {
                    seen.Add(n);
                }
            }

            return -1;
        }

        /// <summary>
        /// Returns the first duplicate from a collection.
        /// </summary>
        /// <param name="collection">List/Array of doubles</param>
        /// <returns>The first duplicated element or -1.</returns>
        public static double FirstDuplicate(IEnumerable<double> collection)
        {
            List<double> seen = new List<double>();

            foreach (var n in collection)
            {
                if (seen.Contains(n))
                {
                    return n;
                }
                else
                {
                    seen.Add(n);
                }
            }

            return -1;
        }


        /// <summary>
        /// Returns the first duplicate from a collection.
        /// </summary>
        /// <param name="collection">List/Array of floats</param>
        /// <returns>The first duplicated element or -1.</returns>
        public static float FirstDuplicate(IEnumerable<float> collection)
        {
            List<float> seen = new List<float>();

            foreach (var n in collection)
            {
                if (seen.Contains(n))
                {
                    return n;
                }
                else
                {
                    seen.Add(n);
                }
            }

            return -1;
        }
    }
}
