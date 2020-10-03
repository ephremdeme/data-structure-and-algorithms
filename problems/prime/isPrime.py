def isPrime(num):
  print(int(num**0.5))
  for i in range(2, int(num**0.5)+1):
    if num%i == 0:
      return False
  return True

print(isPrime(int(input(">>Number: "))))