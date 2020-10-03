#Python Code of Sieve Of Eratosthenes

def findPrime(num) :

    primeNum = [True for index in range(num+1)]
    
    index = 2

    while index <= num :

        if primeNum[index] :

            for index1 in range(index*index, num+1, index) :
                primeNum[index1] = False
        index = index +1
    
    
    return primeNum

def showPrime(prime, num) :

    for index in range(2, num+1):
        
        if prime[index] :
        
            print(index)

def main():

    num = int(input())

    prime = findPrime(num)

    showPrime(prime, num)

if __name__ == "__main__" :
    main()