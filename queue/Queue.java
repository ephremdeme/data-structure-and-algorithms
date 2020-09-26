package arrraylistqueue;
import java.util.ArrayList;
import java.util.Scanner;
class queue
{
	int data;
	int size=0;
	Scanner sb=new Scanner(System.in);
	ArrayList<Integer> arrli = new ArrayList<Integer>();
	void enque()
	{
		System.out.println("Enter data to enque:");
		data=sb.nextInt();
		arrli.add(data);
		size++;
	}
	void deque()
	{
		if(size>0)
	{
		size--;
		arrli.remove(0);
		System.out.println("New array list is:"+arrli);
	}
		else
		{
			System.out.println("queue is empty");
		}
	}
}
public class arraylist {
public static void main(String args[])
{
	queue q=new queue();
	int ch;
	int ans;
	Scanner sb=new Scanner(System.in);
	do
	{
		System.out.println("1.enqueue\n2.deque\n\nEnter your choice");
		ch=sb.nextInt();
		switch(ch)
		{
		case 1:
			q.enque();
			break;
		case 2:
			q.deque();
			break;
		}
		System.out.println("Do you wanna continue?\n1 for yes rest for no\n");
		ans=sb.nextInt();
	}while(ans==1);
}
}
