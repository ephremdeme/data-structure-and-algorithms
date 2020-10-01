function circularLinkedList() {
    // creating a node for the linked list
    let Node = function (nodeValue) {
      	this.element = nodeValue;
      	this.next = null;
    }
  
    let length = 0;
    let head = null;

    // Get node at specific index
    this.getNodeAt = function (index) {
      	if (index >= 0 && index <= length) {
        	let node = head;
        	for (let i = 0; i < index && node != null; i++){
          		node = node.next;
        	}
        	return node;
      	}
      	return undefined;
    }
    
    // Add new node
    this.append = function (element) {
		// create new node
		const node = new Node(element);
		let current;
		
		// If head is empty, then make new node head
		if (head === null) {
			head = node;
		} else {
			// Else add the new node as the next node and mark the next of new node to the head
			current = this.getNodeAt(length - 1);
			current.next = node;
		}
		
		node.next = head;
		length++;
    }
    
    // Insert at given position
    this.insertAtPosition = function (element, index) {
		if (index >= 0 && index <= length) {
			const node = new Node (element);
			let current = head;
			
			// Insert at head
			if (index === 0) {      
				if (head === null) {
					head = node;
					node.next = head;
				} else {
					node.next = current;
					current = this.getNodeAt(length);
					head = node;
					current.next = head;
				}
			} else {
				// Insert at given index (middle or end)
				const previous = this.getNodeAt(index - 1);
				node.next = previous.next;
				previous.next = node;
			}
			
			length++;
			return true;
		}
		return false;
    }
    
    // Remove at any position
    this.removeAt = function (index) {
		if (index >= 0 && index < length) {
			let current = head;
			
			// Remove from head
			if (index === 0) {
				if (length === 1) {
					head = undefined;
				} else {
					const removed = head;
					current = this.getNodeAt(length - 1);
					head = head.next;
					current.next = head;
					current = removed;
				}
			} else {
				// Remove at given index (middle or end)
				const previous = this.getNodeAt(index - 1);
				current = previous.next;
				previous.next = current.next;
			}
			
			length--;
			return current.element;
		}
		return undefined;
    }
    
    // Get the indexOf item 
    this.indexOf = function (elm) {
		let current = head,
		index = -1;
	
		// If element found then return its position
		while (current) {
			if (elm === current.element) {
				return ++index;
			}
			index++;
			current = current.next;
		}
	
		// Else return -1
		return -1;
    };
    
    // Find the item in the list
    this.isPresent = (elm) => {
      	return this.indexOf(elm) !== -1;
    };
    
    // Get the head
    this.getHead = function() {
      	return head;
    }
    
    // Delete an item from the list
    this.delete = (elm) => {
    	return this.removeAt(this.indexOf(elm));
    }; 
    
    // Delete the first item from the list
    this.deleteHead = function() {
      	this.removeAt(0);
    }
    
    // Print item of the string
    this.toString = function() {
		let current = head,
		string = '';
		const temp = head.element;
		
		while (current) {
			if (temp === current.next.element) {
				string += current.element + (current.next ? '\n' : '');
				break;
			}
			string += current.element + (current.next ? '\n' : '');
			current = current.next;
		}
	
		return string;
    };
    
    // Convert list to array
    this.toArray = function() {
		let arr = [],
		current = head;
		const temp = head.element
	
		while (current) {
			// Break if first element detected
			if (temp === current.next.element) {
				arr.push(current.element);
				break;
			}
			arr.push(current.element);
			current = current.next;
		}
	
		return arr;
    };
    
    // Check if list is empty
    this.isEmpty = function() {
      	return length === 0;
    };
    
    // Get the size of the list
    this.size = function() {
      	return length;
    }
    
  }