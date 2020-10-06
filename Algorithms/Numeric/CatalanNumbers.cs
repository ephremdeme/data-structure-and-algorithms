
using System.Diagnostics;
using System.Collections.Generic;
using System.Numerics;

namespace Algorithms.Numeric
{
    public static class CatalanNumbers
    {
        /// Internal cache.
        /// By default contains the first two catalan numbers for the ranks: 0, and 1.
        private static readonly Dictionary<uint, BigInteger> CachedCatalanNumbers = new Dictionary<uint, BigInteger> { { 0, 1 }, { 1, 1 } };

        /// Helper method.
       
        private static BigInteger _recursiveHelper(uint rank)
        {
            if (CachedCatalanNumbers.ContainsKey(rank))
                return CachedCatalanNumbers[rank];

            BigInteger number = 0;
            var lastRank = rank - 1;

            for (uint i = 0; i <= lastRank; ++i)
            {
                var firstPart = _recursiveHelper(i);
                var secondPart = _recursiveHelper(lastRank - i);

                if (!CachedCatalanNumbers.ContainsKey(i)) CachedCatalanNumbers.Add(i, firstPart);
                if (!CachedCatalanNumbers.ContainsKey(lastRank - i)) CachedCatalanNumbers.Add(lastRank - i, secondPart);

                number = number + (firstPart * secondPart);
            }

            return number;
        }

        /// Public API.
      
        public static BigInteger GetNumber(uint rank)
        {
            // Assert the cache is not empty.
            Debug.Assert(CachedCatalanNumbers.Count >= 2);

            return _recursiveHelper(rank);
        }

        /// Calculate the number using the Binomial Coefficients algorithm
      
        public static BigInteger GetNumberByBinomialCoefficients(uint rank)
        {
            // Calculate by binomial coefficient.
            return BinomialCoefficients.Calculate(rank);
        }

        /// Return the list of catalan numbers between two ranks, inclusive
       
        public static List<BigInteger> GetRange(uint fromRank, uint toRank)
        {
            var numbers = new List<BigInteger>();

            if (fromRank > toRank)
                return null;

            for (var i = fromRank; i <= toRank; ++i)
                numbers.Add(GetNumber(i));

            return numbers;
        }
    }
}
