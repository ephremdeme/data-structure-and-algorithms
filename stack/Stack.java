
public class Stack {
	private int top;
	private int max;
	private int stack[];
	
	
	Stack(int max) {
		top = -1;
		this.max = max;
		stack = new int[this.max];
	}
	
	int top() {
		if(!isEmpty())
			return stack[top];
		else {
			System.out.println("stack empty");
			return -1;			
		}

	}

	
	boolean push(int data) {
		if(isFull()) {
			System.out.println("StackOverflow");
			return false;
		}
		stack[++top]=data;
		return true;
	}
	
	boolean isFull() {
		if(top==(max-1))
			return true;
		return false;
	}
	
	boolean isEmpty() {
		if(top<0)
			return true;
		else
			return false;
	}
	
	int pop() {
		if(isEmpty()) {
			System.out.println("StackEmpty");
			return -1;
		}
		int data = stack[top];
		top--;
		return data;
	}
}

public class Main {

	public static void main(String[] args) {
		Stack stack = new Stack(5);
		stack.push(1);
		System.out.println(stack.top());
		System.out.println(stack.pop());
		stack.push(2);
	}

}
