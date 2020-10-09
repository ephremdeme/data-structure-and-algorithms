#inputting the string
s=input("enter a word\n")
l=len(s) #length of word
res=[s+'0',]
c=1
for i in range(l-1):
	s=s[1:]+str(c)
	res.append(s)
	c+=1
	sl=len(s)
	s=s[:sl-1]
rp=[]
res.sort()
for j in res:
	rp.append(int(j[-1]))

print(rp)


	