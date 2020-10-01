fun isPrime(num: Int): Boolean {
        for (i in 2..num / 2) {
            if (num % i == 0) {
                return false
            }
        }
        return true
    }
