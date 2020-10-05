import java.io.*;

class DataItem
{
  private int iData;
  public DataItem(int ii){
    iData=ii;
  }
  public int getKey(){
    return iData;
  }
}  //end class DataItem
////////////////////////////////////////////////
class HashTable
{
  private DataItem[] hashArray;  //array holds hash Hash Table
  private int arraySize;
  private int DataItem nonItem;   //for deleted items

  public HashTable(int size){
    arraySize=size;
    hashArray=new DataItem[arraySize];
    nonItem=new DataItem[-1] ;  //deleted item key is -1
  }

  public void displayTable(){
    System.out.print("Table: ");
    for(int j=0;j<arraySize;j++){
      if(hashArray[j]!=null)
      System.out.print(hashArray[j].getKey() + " ");
      else
      System.out.print("** ");
    }
    System.out.println("");
  }
  public int hashFunc(int key)
  {
    return key%arraySize;   //hash function
  }

  public void insert(DataItem item){
    //(assumes table not full)

      int key=item.getKey();    //extract key
      int hashVal=hashFunc(key);    //hash the key until empty cell or -1
      while(hashArray[hashVal] !=null && hashArray[hashVal].getKey()!=-1)
      {
        ++hashVal;       //go to next cell
        hashVal%=arraySize;     //wrapAround if necessary
      }
      hashArray[hashVal]=item;  //insert item

  }     //end insert

  public DataItem delete(int key){
    int hashVal=hashFunc(key);      //hash the key
    while(hashArray[hashVal]!=null)   //until empty cell
    {
      if(hashArray[hashVal].getKey()==key){
        DataItem temp=hashArray[hashVal];    //save item
        hashArray[hashVal]=nonItem;     //delete item
        return temp;
      }
      ++hashVal;   //go to next cell
      hashVal%=arraySize;
    }
    return null;
  }   //end delete

  public DataItem find(int key){
    int hashVal=hashFunc(key);    //hash the key
    while(hashArray[hashVal]!=null){
      if(hashArray[hashVal].getKey()==key)
      return hashArray[hashVal];
      ++hashVal;      //go to next Item
      hashVal%=arraySize;
    }
    return null;
  }
}     //end class HashTable
//////////////////////////////////////////////////
class HashTableApp
{
  public static void main(String[] args) throws IOException
  {
    DataItem aDataItem;
    int aKey,size,n,keysPerCell;
    System.out.println("Enter size of the hash table: ");
    size=getInt();
    System.out.println("Enter initial number of items:");
    n=getInt();
    keysPerCell=10;
                        //make table
    HashTable theHashTable=new HashTable(size);
    for(int j=0;j<n;j++)
    {
      aKey=(int)(java.lang.Math.random() *keysPerCell*size);
      aDataItem=new DataItem(aKey);
      theHashTable.insert(aDataItem);
    }
    while(true)  //interact with user
    {
      System.out.print("Enter first Letter of");
      System.out.print("show,insert,delete or find:");
      char choice=getChar();
      switch(choice)
      {
      case 's':
        theHashTable.displayTable();
        break;
      case 'i':
        System.out.print("Enter key Value to insert: ");
        aKey=getInt();
        aDataItem=new DataItem(aKey);
        theHashTable.insert(aDataItem);
        break;
      case 'd':
        System.out.print("Enter Key Value to delete: ");
        aKey=getInt;
        theHashTable.delete();
        break;
      case 'f':
        System.out.print("Enter key Value to find: ");
        aKey=getInt();
        aDataItem=theHashTable.find(aKey);
        if(aDataItem!=null)
        {
          System.out.println("Found " + aKey);
        }
        else
        System.out.println("Could not find "+aKey);
        break;
      default:
        System.out.print("Invalid Entry\n");

    }  //end switch
  }     //end while
}       //end main()
public static String getString() throws IOException
{
  InputStreamReader isr=new InputStreamReader(System.in);
  BufferedReader br=new BufferedReader(isr);
  String s=br.readLine();
  return s;
}
public static char getChar() throws IOException
{
  String s=getString();
  return s.charAt(0);
}
public static int getInt() throws IOException
{
  String s=getString();
  return Integer.parseInt(s);
}
//--------------------------------------------------------
}   //end class HashTableApp



//This code is contributed by Ehtesham Khursheed
