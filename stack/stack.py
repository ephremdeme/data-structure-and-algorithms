class Stack:
    items = []

    def push(self, item):
        self.items.append(item)

    def peek(self):
        return self.items[len(self.items) - 1]

    def pop(self):
        if len(self.items) > 0:
            top_item = self.items[0]
            del self.items[0]
            return top_item
        else:
            print("stack empty. Can't pop")

    def print(self):
        print(' '.join(map(str, self.items)))

    def size(self):
        return len(self.items)

my_stack = Stack()
my_stack.push(5)
my_stack.push(10)
my_stack.push(1)
my_stack.print()
print(my_stack.pop(), " popped")
print("stack peek : ", my_stack.peek())
my_stack.push(3)
my_stack.print()
