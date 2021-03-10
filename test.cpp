/*







-------
0/1
dp(i) = dp(i-1) * 2
ans => dp(n)
dp(0) = 1

increasing, monotonic

dp(i) = dp(i - 1) * 2

A = dp(i - 1)
B = A * 2

goto i+1
A = B => (dp(i))
B = A * 2

dp[n] => dp[2]

dp[0] = 1 => i-1
dp[1] => i

for position i
dp[i] = dp[i-1] * 2
dp[1] = dp[0] * 2

before i goto position i + 1
dp[0] = dp[1], assignment

then for position i+1
dp[1] = dp[0] * 2
..
.
.
.
N => 2

2 |2 2| 2 2 
2 |2 2| 2 2
22|2 2| 2 2
2 |2 2| 2 22 
2 |2 2| 2 22

2 2 |2 2| 2
2 2 |2 2| 2
2 2 |2 2| 2 
2 2 |2 2| 2 
2 2 |2 2| 2


dp[0] i-1th

dp[1] ith

i+1th?
dp[1] i
dp[0] i+1

i+2th?

dp[0] i+1
dp[1] i+2

p = 0

dp[p] => prev
dp[!p] => current

dp[!p] = dp[p] * 2
p = !p









2 * 900 * 2 * 10^5 * 2
3.6 * 10^8












*/