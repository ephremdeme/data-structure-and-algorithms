def towerOfHanoi(n, where, to, extra):
    if n == 0:
        return
    else:
        towerOfHanoi(n-1, where, extra, to)
        print("Move disk :", n, "from", where, "to", to)
        towerOfHanoi(n-1, extra, to, where)
        
n = int(input("number of Disks : "))

print("Process of moving all disks form A to C is -")

towerOfHanoi(n, "A", "B", "C")