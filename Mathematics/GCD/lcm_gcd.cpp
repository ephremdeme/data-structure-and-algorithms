#include <iostream> 

using namespace std;

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
	cout << "lcm of 10, 35 is: " << lcm(10, 35) << "\n";
	cout << "gcd of 10, 35 is: " << gcd(10, 35) << "\n";
    return 0;
}
