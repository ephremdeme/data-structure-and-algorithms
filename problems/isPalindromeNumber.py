# python 2.7

def is_palindrome_number(number):
  if number >= 0 and number < 10:
    return True
  elif number % 10 == 0:
    return False

  return is_palindrome_number_rec(number, 0)

def is_palindrome_number_rec(head, tail):
  new_head = head/10
  new_tail = tail*10 + head%10

  if head == tail:
    return True
  elif new_head == tail:
    return True
  elif tail >= head:
    return False
  else:
    return is_palindrome_number_rec(new_head, new_tail)


print is_palindrome_number(-1) # false
print is_palindrome_number(0) # true
print is_palindrome_number(1) # true
print is_palindrome_number(10) # false
print is_palindrome_number(101) # true
print is_palindrome_number(1010) # false
print is_palindrome_number(1221) # true
print is_palindrome_number(12321) # true
