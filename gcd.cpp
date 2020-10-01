//Euclid's GCD/HCF Algorithm
//O(log N)
//1)GCD(a,b)=GCD(b,a%b)
//2)GCD(a,0)=a
//Compute HCF & LCM
//gcd*LCM = a*b
#include<iostream>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	int GCD= gcd(n1, n2);`
	int LCM = (n1 * n2) / GCD;
	cout << GCD << " " << LCM;
	return 0;
}
