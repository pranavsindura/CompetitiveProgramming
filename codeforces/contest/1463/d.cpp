#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e7;
const int MAXN = 1e5 + 5;


/*
picked are
1 4 5 9 10
remaining are
2 3 6 7 8

x =
0 no
1 yes
2 yes
3 yes
4 no
5 no

either 0 is possible or n is possible or neither, both cannot occur, manually check 0 and n

Sort the picked and not picked numbers
Assumption/Intuition -
for a given x
we will take the first x picked values and make them the minimum pairs, for this
we will take the last x from the not picked values and pair them together
If the pairing results in the actual set then this x is valid else it is not

n = 5

picked     2 3 6 7 8
not picked 1 4 5 9 10
0 no
1 no
2 yes
3 yes
4 yes
5 no

for each index in picked we find how many numbers it is bigger than (prefix) and smaller than (suffix)
Then for a given x we need to partition the arrays into so
Picked: ...first x... | ...remaining n-x...
Not picked: ...remaining n-x... | ...last n-x...

We need to then check if all elements in the first x of Picked are < all elements in last x of Not picked
and remaining n-x of Picked > remaining n-x of Not picked

We can do them individually and then combine the results
*/


void cp()
{
    int n;
    cin >> n;
    vector<int> A(n), picked(2 * n + 1), B;
    for(int &x : A)
        cin >> x, picked[x] = 1;

    for(int i = 1; i <= 2 * n; i++)
        if(!picked[i])
            B.push_back(i);

    sort(all(A));

    vector<pi> arr(n);

    bool can_zero = true, can_all = true;
    for(int i = 0; i < n; i++)
    {
        can_zero &= (A[i] > B[i]);
        can_all &= (A[i] < B[i]);
    }

    vector<int> L(n), G(n), canL(n), canG(n);
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        while(j < n && A[i] > B[j]) j++;
        L[i] = n - j;
        L[i] = min(L[i], n - i);
        G[i] = j;
        G[i] = min(G[i], i + 1);
    }

    int cnt = n + 1;
    for(int i = 0; i < n; i++)
    {
        cnt--;
        cnt = min(cnt, L[i]);
        if(cnt > 0)
            canL[i] = 1;
    }
    cnt = n + 1;
    for(int i = n - 1; i >= 0; i--)
    {
        cnt--;
        cnt = min(cnt, G[i]);
        if(cnt > 0)
            canG[i] = 1;
    }

    int ans = can_zero + can_all;
    for(int i = 0; i < n - 1; i++)
        ans += canL[i] && canG[i + 1];

    cout << ans << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}
