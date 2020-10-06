''' A basic Stack implementation in Python using Linked List, 
    with the following functionalities implemented:
	-Push operation 
	-Pop operation
	-Display stack
'''

class Node:
    def __init__(self,data): 
        self.data = data 
        self.next = None
      
class Stack:
    def __init__(self): 
        self.head = None
    
    def isempty(self): 
        
        if self.head == None: 
            return True
        else: 
            return False
    
    def insertElement(self,data): 
          
        if self.head == None: 
            self.head=Node(data) 
              
        else: 
            newnode = Node(data) 
            newnode.next = self.head 
            self.head = newnode 
        
        print("\n")
      
    def deleteElement(self): 
          
        if self.isempty(): 
            return None
              
        else:
            poppednode = self.head 
            self.head = self.head.next
            poppednode.next = None
            return poppednode.data 
        
    def printStack(self): 
          
        iternode = self.head 
        if self.isempty(): 
            print("Stack Underflow") 
          
        else: 
            while(iternode != None): 
                print(iternode.data,end = " ")
                iternode = iternode.next
                if iternode is not None:
                    print("->", end=" ")
            return
        print("\n")
        
        
if __name__ == "__main__":
    lst = Stack()
    
    while True:
        print("Select the any option")
        print("[1] Insert Element")
        print("[2] Delete Element")
        print("[3] Print List")
        print("[4] Exit")
        print("\n")
        i = int(input())
        print("\n")

        if i == 1:
            lst.insertElement(input("Enter data you want to insert: "))
        elif i == 2:
            lst.deleteElement()
        elif i == 3:
            lst.printStack()
        elif i == 4:
            break
        