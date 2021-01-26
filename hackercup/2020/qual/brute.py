import heapq

for testcases in range(int(input())):
    n,m = list(map(int,input().split()))
    arr = []
    for i in range(n):
        arr.append(int(input()))
    cost = [10**20 for i in range(n)]
    cost[0] = 0 
    l = [[m,0,0]]
    heapq.heapify(l)
    while l!=[]:
        x = heapq.heappop(l)
        # print(len(l))
        # print(x)
        p,c,ind = x
        for i in range(ind+1,min(n,ind+1+p)):
            
            if arr[i]!=0 and cost[i]>c:
                heapq.heappush(l,[m,c+arr[i],i])
            cost[i] = min(cost[i], c)
        # print(cost)
        # print()
    if cost[-1]==10**20:
        ans = -1
    else:
        ans = cost[-1]
    print('Case #'+str(testcases+1)+': ',ans)