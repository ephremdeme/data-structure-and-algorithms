import java.util.*;
import java.lang.*;

/**
 * Palindrome
 */
public class Palindrome {
    static boolean isPalindrome(String s) {

        // Left and right pointers pointing to the beginning and the end of the string 

        int left = 0, right = s.length() - 1;
        
        while (left < right) { 
  
            // If there is a mismatch 

            if (s.charAt(left) != s.charAt(right)) 
                return false; 
  
            // Increment left pointer and decrement right pointer
            left++; 
            right--; 
        } 
        return true; 
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in); 

        String str = sc.nextLine(); //Input a string
        
        System.out.println(isPalindrome(str)); // Print whether the input string is palindrome or not
    
    }
}
