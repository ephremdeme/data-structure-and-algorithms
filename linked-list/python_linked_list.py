#python_linked_list.py
#
#Name: Salad
#
#Date: 26/09/2020
#
#Description: an implementation  of the linked list data structure in python
#             I decided to go with just one class, each node can be perceived as a list + im lazy

class linked_list_node:

    def __init__(self, data, next):
        self.data = data
        self.next = next

    def search_by_data(self, data):

        """get data and check every node in the list for the data, if found return the node
            return none if nothing was found"""
        temp = self

        #loop through the list
        while(temp != None):

            if temp.data == data:
                return temp
            
            temp = temp.next

        return None
    
    def delete_last(self):
        """delete the last node"""

        temp = self

        #loop through the list
        while(temp.next.next != None):
            temp = temp.next
        
        temp.next = None

    def delete_by_data(self, data):

        """search for a node that contains the data and delete the node"""
        
        #check if data is on self
        if self.data == data:
            self = self.next
            return

        temp = self

        #loop through the list until the node is found
        while(temp.next != None):

            if temp.next.data == data:
                temp.next = temp.next.next
                return
            
            temp = temp.next
    
    def insert_to_end(self, new_node):
        """insert given node to the end of the list"""

        temp = self

        #get to the end of the list
        while(temp.next != None):
            temp = temp.next

        temp.next = new_node

    def print_contents(self):
        """print the contents of all the nodes in the list"""

        temp = self

        #loop through the list and print data of each node
        while(temp != None):
            print(temp.data)

            temp = temp.next

