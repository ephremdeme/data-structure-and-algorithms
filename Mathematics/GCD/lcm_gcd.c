#include <stdio.h> 

// recursive function to return gcd of a and b 
int gcd(int a, int b) {
	/*please see: https://en.wikipedia.org/wiki/Euclidean_algorithm*/
	if (b == 0) return a;
	return gcd(b, a % b);
}

// function to return LCM of two numbers 
int lcm(int a, int b) {
	/*
	a * b = lcm(a, b) * gcd (a, b)
	lcm(a, b) = (a * b) / gcd(a, b)
	*/
	return (a / gcd(a, b)) * b;
}

int main() {
	printf("lcm of 10, 35 is: %d\n", lcm(10, 35));
	printf("lcm of 10, 35 is: %d\n", gcd(10, 35));
    return 0;
}
