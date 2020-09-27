public static int reverseNumber(int num)
{
   int ans=0;
   while(num>0){
      int remainder=num%10;
      ans=ans*10+remainder;
      num=num/10;
      }
   return ans;
}
