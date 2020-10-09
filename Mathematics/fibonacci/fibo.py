import sys
limit = int(input('Enter number of terms '))
no1 , no2 = 0, 1
if limit == 0:
    sys.exit()
else:
    print(no1, end = " ")
    for i in range(0, limit-1):
        no2 = no1 + no2
        no1 = no2 - no1
        print(no1, end = " ")
