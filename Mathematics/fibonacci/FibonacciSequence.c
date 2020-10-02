

/**
 * GitHub username: chinmaykumbhare
 *
 * Issue Statement:
 * Implement Fibonacci sequence in any language. Recursive is appreciated.
 */

#include <stdio.h>

void main (void) {

	int num = 0;

	//enter the number of elements you would like to display as output

	scanf(" %d", &num);

	//using 3 variables, namely, prev for previous term. current for current term and next for next term in the sequence

	int prev = 0, current = 1, next = 1;

	//loop for calculating and printing the next number in fibonacci series

	for(int loop = 0; loop < num; loop++) {

		printf("%d ", prev);

		next = current + prev;

		prev = current;

		current = next;

	}

	printf("\n");

}
