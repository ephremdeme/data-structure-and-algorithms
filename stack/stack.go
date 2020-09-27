// Package stack provides an array implementation
// of stack data structure
package stack

import (
	"fmt"
)

// Stack definition
type Stack struct {
	top  int
	data []interface{}
}

// Push an int onto the stack
func (s *Stack) Push(x interface{}) {
	s.data = append(s.data, x)
	s.top++
}

// Pop removes the top element from the stack
func (s *Stack) Pop() interface{} {
	if s.top < 0 {
		fmt.Println("The stack is empty.")
	}

	s.top--
	temp := s.data[s.top]
	s.data = s.data[:len(s.data)-1]
	return temp
}

// Size returns the length of data
func (s Stack) Size() int {
	return len(s.data)
}

// Allows print the stack's content
func (s Stack) String() string {
	var str string
	for i := 0; i < s.top; i++ {
		str = str + fmt.Sprintf("[ %d: %v ]", i, s.data[i])
	}

	return str
}
