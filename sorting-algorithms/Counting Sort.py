//This is the code for counting sort which is useful in many questions.
arr=list(map(int,input().split()))
am=max(arr)
b=[0]*(am+1)
for i in arr:
    b[i]+=1
for i in range(1,am+1):
    b[i]+=b[i-1]
c=[0]*(b[am])
for i in range(len(arr)-1,-1,-1):
    d=arr[i]
    b[d]-=1
    c[b[d]]=d
arr=c
print(arr)
