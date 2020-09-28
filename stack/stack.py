class Stack:
  def __init__(self):
    self._data = []
    self.size = 0
  
  def push(self, value, *args):
    self._data.append(value)
    for item in args:
      self._data.append(item)
    self.size += 1

  def pop(self):
    self._data.pop(-1)
    self.size -= 1

  def peek(self):
    return self._data[-1]

  def printStack(self):
    return ('[ ' + ', '.join(map(lambda item: str(item), self._data)) + ']')

myStack = Stack();
myStack.push(5)
myStack.push(10)
myStack.push(89)
print("Peek:", myStack.peek())
myStack.pop()
print("Peek:", myStack.peek())
print(myStack.printStack())
  