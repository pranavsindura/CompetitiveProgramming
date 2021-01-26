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

string S, A, B;
vector<int> fA, fB;

int dp[1005][55][55];
int toA[26][55], toB[26][55], valA[26][55], valB[26][55];

void cp()
{
    cin >> S >> A >> B;

    fA.assign(ln(A), 0);
    fB.assign(ln(B), 0);

    for(int i = 1, k = 0; i < ln(A); i++)
    {
        while(k && A[i] != A[k]) k = fA[k - 1];
        if(A[i] == A[k]) k++;
        fA[i] = k;
    }
    for(int i = 1, k = 0; i < ln(B); i++)
    {
        while(k && B[i] != B[k]) k = fB[k - 1];
        if(B[i] == B[k]) k++;
        fB[i] = k;
    }

    for(char c = 'a'; c <= 'z'; c++)
    {
        // toA[c][i], where i go if char is c and my match is at i
        for(int x = 0; x < ln(A); x++)
        {
            int u = x;
            while(u && A[u] != c) u = fA[u - 1];
            if(A[u] == c) u++;
            if(u == ln(A)) valA[c - 'a'][x] = 1, u = fA[u - 1];
            toA[c - 'a'][x] = u;
        }

        for(int y = 0; y < ln(B); y++)
        {
            int v = y;
            while(v && B[v] != c) v = fB[v - 1];
            if(B[v] == c) v++;
            if(v == ln(B)) valB[c - 'a'][y] = -1, v = fB[v - 1];
            toB[c - 'a'][y] = v;
        }
    }

    for(int i = 0; i < ln(S); i++)
        for(int x = 0; x < ln(A); x++)
            for(int y = 0; y < ln(B); y++)
                dp[i][x][y] = -inf, dp[ln(S)][x][y] = 0;


    for(int i = ln(S) - 1; i >= 0 ; i--)
        for(int x = 0; x < ln(A); x++)
            for(int y = 0; y < ln(B); y++)
                for(char c = 'a'; c <= 'z'; c++)
                    if(S[i] == '*' || S[i] == c)
                    {
                        int &ans = dp[i][x][y];
                        int me = valA[c - 'a'][x] + valB[c - 'a'][y];
                        ans = max(ans, me + dp[i + 1][toA[c - 'a'][x]][toB[c - 'a'][y]]);
                    }

    cout << dp[0][0][0] << endl;
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

