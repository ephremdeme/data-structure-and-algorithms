# Input number from the user
N = int(input("Enter the number to be reversed "))
 
# Initiate value to null. R will store the value of the reverse of user input
R = 0
 
# Check using while loop
 
while(N>0):
  #Logic
  remainder = N % 10
  R = (R * 10) + remainder
  N = N//10
 
# Print the output
print("The reverse number is: {}".format(R))
