// Linear Search in Golang,

package main

import "fmt"

func main() {
	items := []int{1, 12, 13, 14, 17, 99, 100, 21, 33}
	fmt.Println(linearSearch(items, 12))
}

func linearSearch(array []int, key int) int {
	for index, value := range array {
		if key == value {
			return index
		}
	}
	return -1
}
