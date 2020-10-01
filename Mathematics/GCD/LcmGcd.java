public class LcmGcd {

// recursive function to return gcd of a and b 
private static int gcd(int a, int b) {
	/*please see: https://en.wikipedia.org/wiki/Euclidean_algorithm*/
	if (b == 0) return a;
	return gcd(b, a % b);
}

// function to return LCM of two numbers 
private static int lcm(int a, int b) {
	/*
	a * b = lcm(a, b) * gcd (a, b)
	lcm(a, b) = (a * b) / gcd(a, b)
	*/
	return (a / gcd(a, b)) * b;
}

	public static void main(String[] args) {
		System.out.println("lcm of 10, 35 is: " + lcm(10, 35));
		System.out.println("gcd of 10, 35 is: "  + gcd(10, 35));
	}
}
