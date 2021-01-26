def conc(x,y):
    binx = bin(x)[2:]
    biny = bin(y)[2:]
    
    binxy = binx+biny
    binyx = biny+binx

    return(abs((int(binxy,2)-int(binyx,2))))
    
for _ in range(int(input())):
    n = int(input())
    ls = list(map(int,input().split(' ')))
    
    ls.sort()
    
    maxi =-1
    ansa=0
    ansb=0
    ans =0
    for i in range(0,n):
        ans = conc(ls[i],ls[-1])
        if(maxi<ans):
            maxi = ans;
            ansa = ls[i]
            ansb = ls[-1]
    
    print(maxi)            