package main

import (
	"fmt"
)

func fibonacci(limit int) {
	if limit >= 1 {
		fmt.Printf("%d", 1)
	}

	a, b := 1, 1

	for b <= limit {
		fmt.Printf(", %d", b)
		a, b = b, a+b
	}

	fmt.Println()
}

func main() {
	fibonacci(8)
	fibonacci(123)
	fibonacci(1)
	fibonacci(50)
	fibonacci(100)
}
