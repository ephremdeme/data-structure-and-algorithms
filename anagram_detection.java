// JAVA program to detect anagrams
import java.io.*; 
import java.util.Arrays; 
import java.util.Collections; 

public class anagram_detection { 

	/* function to check if two strings are anagrams */
	static boolean areAnagram(char[] str1, char[] str2) 
	{ 
		// Obtain the lengths
		int s1 = str1.length; 
		int s2 = str2.length; 

		// Check length
		if (s1 != s2) 
			return false; 

		// Sort the strings 
		Arrays.sort(str1); 
		Arrays.sort(str2); 

		// Compare sorted strings 
		for (int i = 0; i < s1; i++) 
			if (str1[i] != str2[i]) 
				return false; 

		return true; 
	} 

	/* Main function*/
	public static void main(String args[]) 
	{ 
		char str1[] = { 'w', 'e', 's', 't' }; 
		char str2[] = { 't', 't', 'e', 'w' }; 
		if (areAnagram(str1, str2)) 
			System.out.println("The two strings are"
							+ " anagram"); 
		else
			System.out.println("The two strings are not"
							+ " anagram"); 
	} 
} 
