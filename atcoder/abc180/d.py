x,y,a,b = map(int, input().split())

ops = 0
    
while x < y:
    if x * a < x + b:
        x = x * a
        if x < y:
            ops += 1
    else:
        # always take b
        ops += (y - x - 1) // b
        break
print(ops)