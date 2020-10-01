package main

import "fmt"

// recursive function to return gcd of a and b
func gcd(a int, b int) int {
	/*please see: https://en.wikipedia.org/wiki/Euclidean_algorithm*/
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

// function to return LCM of two numbers
func lcm(a int, b int) int {
	/*
		a * b = lcm(a, b) * gcd (a, b)
		lcm(a, b) = (a * b) / gcd(a, b)
	*/
	return (a / gcd(a, b)) * b
}

func main() {
	fmt.Println("lcm of 10, 35 is: ", lcm(10, 35))
	fmt.Println("lcm of 10, 35 is: ", gcd(10, 35))
}

