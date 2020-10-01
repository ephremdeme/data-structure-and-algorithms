# function to check if two strings are 
# anagram or not  
def check(s1, s2): 
      
    # the sorted strings are checked  
    if(sorted(s1)== sorted(s2)): 
        print(True)  
    else: 
        print(False)   
        
words = input("Enter two words with &: ")          
word1 = words.split(" & ")[0]
word2 = words.split(" & ")[1]
check(word1, word2)
