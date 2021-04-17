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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

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
    int n, k;
    cin >> n >> k;
    vector<int> A(k);
    for(int &x : A)
        cin >> x;
    stack<int> S;
    vector<int> B;

    bool ok = true;
    vector<bool> instack(n + 1), have(n + 1);
    for(int x : A) have[x] = true;

    int need = 1;
    int i = 0;
    while(i < k && ok)
    {
        if(instack[need])
        {
            if(S.top() == need)
                S.pop(), B.push_back(need), instack[need] = false, need++;
            else
                ok = false;
        }
        else
        {
            while(i < k && A[i] != need)
                S.push(A[i]), instack[A[i]] = true, i++;
            if(i < k)
                S.push(A[i]), instack[A[i]] = true, i++;
        }
    }

    while(!S.empty() && instack[need] && S.top() == need)
        S.pop(), B.push_back(need), instack[need] = false, need++;

    while(need <= n && ok)
    {
        int x = need;
        vector<int> T;
        while(x <= n && !have[x])
            T.push_back(x), have[x] = true, x++;
        while(!T.empty()) A.push_back(T.back()), T.pop_back();

        if(instack[need])
        {
            if(S.top() == need)
                S.pop(), B.push_back(need), instack[need] = false, need++;
            else
                ok = false;
        }
        else
        {
            while(i < sz(A) && A[i] != need)
                S.push(A[i]), instack[A[i]] = true, i++;
            if(i < sz(A))
                S.push(A[i]), instack[A[i]] = true, i++;
        }
    }

    if(ok)
    {
        for(int x : A)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
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
