def Kadanes(arr): 
    maxval = 0
    maxcheck = 0 
    for i in arr: 
        maxcheck += i 
        if maxval < maxcheck: 
            maxval = maxcheck 
        elif maxcheck < 0: 
            maxcheck = 0
              
    return maxval 
