//Stack Implementation using Array
class StackX
{
  private int maxSize;
  private long[] stackArray;
  private int top;

  public StackX(int s)    //Constructor
  {
    maxSize=s;
    top=-1;
    stackArray=new long[maxSize];
  }
  public void push(long j)    //put item on top of Stack
  {
    stackArray[++top]=j;
  }
  public long pop(){      //take item from top of Stack
    return stackArray[top--];
  }
  public long peek     //peek at top of Stack
  {
    return stackArray[top];
  }
  public boolean isEmpty()     //true if Stack is Empty
  {
    return (top==-1);
  }
  public boolean isFull()    //true if Stack is full
  {
    return (top==maxSize-1)
  }
}     //end Class StackX

class StackApp
{
  public static void main(String[] args)
  {
    Stack theStack=new StackX(10);    //Make new Stack of Size 10
    theStack.push(20);     //pushing items into Stack
    theStack.push(40);
    theStack.push(60);
    theStack.push(80);

    while(!theStack.isEmpty())      //until it's Empty
    {
      long value=theStack.pop();    //Remove items from Stack
      System.out.print(value);      //Display it
      System.out.print(" ");
    }
    System.out.println("");
  } // end main
}


// This code is Contributed by Ehtesham Khursheed
