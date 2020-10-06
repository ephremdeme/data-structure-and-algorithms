import java.util.*;
class node {
	String custname;
	String telephone; // to have valid mobile number
	node left;
	node right;
	int h;

	node() // default constructor
	{
		left = null;
		right = null;
		h = 0;
	}
}
class avl {
	Scanner sc = new Scanner(System.in);
	int bal;
	node root;

	avl()				//default constructor 
	{			
		root = null;
	}

	int heightl(node ptr)				//calculating height of avl tree			
	{
		int lh;
		int rh;	
		if(ptr==null)
		{
			return 0;
		}
		else
		{
			if(ptr.left==null)
			{
				 lh= 0;
			}
			else
			{
				lh= 1+ptr.left.h;
			}
			if(ptr.right==null)
			{
				 rh= 0;
			}
			else
			{
				rh= 1+ptr.right.h;
			}
		}
		return max(lh,rh);
	}
	int max(int a,int b)						//calculating max of 2 variables
	{
		if(a>b)
		{
			return a;
		}
		else
			return b;
	}
	int balance_factor(node ptr)				//calculating balance factor
	{
		int lh;
		int rh;
		int bal_fact=0;	
		if(ptr==null)
			return 0;
		else
		{
			if(ptr.left==null)	
				 lh= 0;
			else
				lh= 1+ptr.left.h;
			if(ptr.right==null)
				 rh= 0;
			else
				rh= 1+ptr.right.h;
		}
		bal_fact=lh-rh;
		return bal_fact;
	}
	node ll(node ptr)					//function for ll rotation
	{	
        	node p;
       	 	p=ptr.left;
        	ptr.left=p.right;
       	 	p.right=ptr;
        	ptr.h=heightl(ptr);				//calling height function
        	p.h=heightl(p);
        	return p;
	}
	node rr(node ptr)					//function for rr rotation
	{
        	node p;
        	p=ptr.right;
        	ptr.right=p.left;
        	p.left=ptr;
        	ptr.h=heightl(ptr);
        	p.h=heightl(p);
        	return p;
	}
	node lr(node ptr)					//function for lr rotation
	{
        	ptr.left=rr(ptr.left);
        	ptr=ll(ptr);
        	return ptr;
	}
	node rl(node ptr)					//function for rl rotation
	{
	        ptr.right=ll(ptr.right);
        	ptr=rr(ptr);
        	return ptr;
	}
	node insert(String name,String tele_no,node root)	//function for creating avl tree
	{
		int bal_fact;
		if(root==null)
		{
			node temp=new node();
		    temp.custname=name;
		    temp.telephone=tele_no;
		    return temp;
		}
		else
		{
			if(name.compareTo(root.custname)<0)
			{
				root.left=insert(name,tele_no,root.left);
				bal_fact=balance_factor(root);
				if(bal_fact==2)
				{
					if(name.compareTo(root.left.custname)<0)
					{
					       root=ll(root);		//calling ll rotation
					       System.out.println("\tLL");
					       levelorder();
					}
					else
					{
						root=lr(root);		//calling lr rotation
						System.out.println("\tLR");
						levelorder();
					}			
				}
			}
			else
			{
				root.right=insert(name,tele_no,root.right);
				bal_fact=balance_factor(root);
				if(bal_fact==-2)
				{
					if(name.compareTo(root.right.custname)>0)
					{
					       root=rr(root);		//calling rr rotation
					       System.out.println("\tRR");
					       levelorder();
					}
					else
					{
						root=rl(root);		//calling rl rotation
						System.out.println("\tRL");	
						levelorder();
					}
				}						
			}
		}
		root.h=heightl(root);
		return root;
	}
	
	void insert1()
	{
		int ans;
		do
		{
			System.out.print("\nEnter name:");
			String name = sc.next();
			System.out.print("Enter mobile number:");
			String tele_no = sc.next();			 		  
			if(tele_no.length()<10||tele_no.length()>10	)		//validation for mobile number
			{
				System.out.print("\nInvalid entry. Enter valid mobile no.:");
				tele_no=sc.next();
			}  
			root=insert(name,tele_no,root);			//calling create function
			System.out.print("\nDo you want to continue?(1/0)");
			ans=sc.nextInt();	
		}while(ans!=0);
		
	}


	// traversals
	public void preorder(node root) {
		if (root != null) {
			System.out.println("\n"+root.custname + " " + root.telephone);
			preorder(root.left);
			preorder(root.right);
		}
	}

	public void postorder(node root) {
		if (root != null) {
			postorder(root.left);
			postorder(root.right);
			System.out.println("\n"+root.custname + " " + root.telephone);
		}
	}

	public void inorder(node root) {
		if (root != null) {
			inorder(root.left);
			System.out.println("\n"+root.custname + " " + root.telephone);
			inorder(root.right);
		}
	}

	public void display() {
		System.out.println("\npreorder:\n ");
		preorder(root);
		System.out.println("\npostorder:\n ");
		postorder(root);
		System.out.println("\ninorder:\n ");
		inorder(root);
		System.out.println("\nlevelorder:\n ");
		levelorder();
	}

	public void levelorder() // function for levelorder display of avl tree
	{
		node ptr;
		ptr = root;
		Queue<node> Q = new LinkedList<node>();
		Q.add(ptr);
		while (ptr != null) {
			ptr = Q.remove();
			System.out.println("\t" + ptr.custname + ":" + ptr.telephone);
			if (ptr.left != null) {
				Q.add(ptr.left);
			}
			if (ptr.right != null) {
				Q.add(ptr.right);
			}
			System.out.println("\t");
			if (Q.isEmpty()) {
				break;
			}
		}
	}
}

public class avltree {

	private static Scanner sc;

	public static void main(String[] args) {
		char ch;
		int c;
		avl b = new avl();
		sc = new Scanner(System.in);
		System.out.println("\nCREATE BINARY TREE:");
		do {
			System.out.print("\n1.INSERT\n2.DISPLAY\n\nENTER YOUR CHOICE:");
			c = sc.nextInt();
			switch (c) {
			case 1:
				b.insert1();
				break;
			case 2:
				b.display();
				break;
			}
			System.out.println("DO YOU WANT TO CONTINUE OPERATIONS OF AVL TREE?(y/n)\n");
			ch = sc.next().charAt(0);
		} while (ch == 'y');
	}
}