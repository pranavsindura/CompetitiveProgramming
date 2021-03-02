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

vector<pair<ll, char>> reduce(vector<pair<ll, char>> &A)
{
    int n = sz(A);
    vector<pair<ll, char>> P;
    P.push_back(A[0]);
    for(int i = 1; i < n; i++)
    {
        if(A[i].second == P.back().second)
            P.back().first += A[i].first;
        else
            P.push_back(A[i]);
    }
    return P;
}

void cp()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, char>> A(n), B(m);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        char c = s.back();
        s.pop_back(), s.pop_back();
        int x = stoi(s);
        A[i] = {x, c};
    }
    for(int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        char c = s.back();
        s.pop_back(), s.pop_back();
        int x = stoi(s);
        B[i] = {x, c};
    }

    A = reduce(A);
    B = reduce(B);
    n = sz(A), m = sz(B);

    if(m == 1)
    {
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i].second != B[0].second || A[i].first < B[0].first) continue;
            ans += A[i].first - B[0].first + 1;
        }
        cout << ans << endl;
    }
    else if(m == 2)
    {
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(A[i].second != B[0].second || A[i].first < B[0].first) continue;
            if(A[i + 1].second != B[1].second || A[i + 1].first < B[1].first) continue;
            ans++;
        }
        cout << ans << endl;
    }
    else
    {
        auto L = B.front(), R = B.back();
        B.pop_back();
        reverse(all(B));
        B.pop_back();
        reverse(all(B));

        m = sz(B);
        vector<int> failure(m);
        for(int i = 1, k = 0; i < m; i++)
        {
            while(B[i] != B[k] && k) k = failure[k - 1];
            if(B[i] == B[k]) k++;
            failure[i] = k;
        }

        int ans = 0;
        for(int i = 0, k = 0; i < n; i++)
        {
            while(A[i] != B[k] && k) k = failure[k - 1];
            if(A[i] == B[k]) k++;
            if(k == m)
            {
                int j = i - m + 1;
                if(
                    j - 1 >= 0 && i + 1 < n &&
                    A[j - 1].first >= L.first && A[j - 1].second == L.second &&
                    A[i + 1].first >= R.first && A[i + 1].second == R.second
                )
                    ans++;
                k = failure[k - 1];
            }
        }

        cout << ans << endl;
    }
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
