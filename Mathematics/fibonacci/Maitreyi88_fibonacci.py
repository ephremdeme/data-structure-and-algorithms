#!/usr/bin/env python
# coding: utf-8

# In[30]:


a= int(input("Input integer: "))
def fibo(a):
    a1, a2 = 0, 1
    a3 = 0
    if a == 1:
        print("Fibonacci sequence upto",a,":",a1)
    else:
        print("Fibonacci sequence:")
        while  a3 <= a:
            print(a1,end=" ")
            a3 = a1 + a2
            a1 = a2
            a2 = a3
fibo(a)

  

