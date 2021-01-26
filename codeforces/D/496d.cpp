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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n), A, B;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] == 1) A.push_back(i);
        else B.push_back(i);
    }

    vector<vector<int>> ans;

    for(int T = 1; T <= n; T++)
    {
        int idx = 0;
        bool ok = true;
        int winA = 0, winB = 0;
        bool who = false;
        while(ok && idx < n)
        {
            int pA = lower_bound(all(A), idx) - begin(A);
            int pB = lower_bound(all(B), idx) - begin(B);
            if(sz(A) - pA < T && sz(B) - pB < T) ok = false;
            else if(sz(A) - pA < T)
            {
                winB++;
                idx = B[pB + T - 1] + 1;
                who = 1;
            }
            else if(sz(B) - pB < T)
            {
                winA++;
                idx = A[pA + T - 1] + 1;
                who = 0;
            }
            else
            {
                if(A[pA + T - 1] < B[pB + T - 1]) winA++, idx = A[pA + T - 1] + 1, who = 0;
                else winB++, idx = B[pB + T - 1] + 1, who = 1;
            }
        }
        ok &= (winA != winB);
        bool actual = winA < winB;
        ok &= (actual == who);
        if(ok) ans.push_back({max(winA, winB), T});
    }

    sort(all(ans));
    cout << sz(ans) << endl;
    for(auto v : ans)
        cout << v[0] << " " << v[1] << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

