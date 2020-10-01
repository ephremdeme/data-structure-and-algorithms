package fibonacci

import java.util.*
import java.util.Collections.emptyList

/**
 * Calculate list of Fibonacci numbers that are less than or
 * equal to a given upper limit
 *
 * @param upperLimit upper limit
 * @return list of Fibonacci numbers <= upperLimit
 */
fun fibonacciNumbers(upperLimit: Int) : List<Int> {

    if (upperLimit <= 0) {
        return emptyList()
    }

    val result = mutableListOf(1, 1)

    while (true) {
        val next = result[result.size - 2] + result.last()
        if (next <= upperLimit) {
            result.add(next)
        } else {
            return result
        }
    }
}

fun readUpperLimit(scanner: Scanner) : Int {

    while (true) {
        print("Upper limit for Fibonacci numbers: ")
        try {
            return scanner.nextInt()
        } catch (err: InputMismatchException) {
            println("Please enter an integer!")
            scanner.nextLine()
        }
    }

}

fun main() {

    println(fibonacciNumbers(readUpperLimit(Scanner(System.`in`))))

}