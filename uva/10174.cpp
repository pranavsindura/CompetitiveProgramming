#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

int bachelor[MAXN];

void init()
{
    for(int i = 0; i * i < MAXN; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            int a = i * i, b = j * j;
            // i*i - j*j is a square couple
            bachelor[a - b] = 1;
        }
    }
    for(int i = 0; i < MAXN; i++)
    {
        if(!bachelor[i])
            // it is not a square couple
            // if it is even, then it is bachelor
            bachelor[i] = (i % 2 == 0);
        else
            bachelor[i] = 0;
        if(i)
            bachelor[i] += bachelor[i - 1];
    }
}

inline bool ok(int x)
{
    return x >= 0 && (int)sqrt(x) * (int)sqrt(x) == x;
}

void cp()
{
    string s;
    while(getline(cin, s) && !s.empty())
    {
        vector<int> arr;
        stringstream ss(s);
        int x;
        while(ss >> x)
            arr.pb(x);
        if(sz(arr) > 1)
        {
            int cnt = 0;
            int l = arr[0], r = arr[1];
            for(int i = l; i <= r; i++)
                if(i % 2 == 0 && i % 4 != 0)
                    cnt++;

            cout << cnt << endl;
        }
        else
        {
            int n = arr[0];
            int sg = (n >= 0 ? 1 : -1);
            n *= sg;
            int a = -1, b = -1;

            if(n % 4 == 0)
            {
                int p = n / 2, q = 2;
                if(p < q)
                    swap(p, q);
                a = (p + q) / 2, b = (p - q) / 2;
            }
            else if(n & 1)
            {
                int p = n, q = 1;
                a = (p + q) / 2, b = (p - q) / 2;
            }

            if(sg < 0)
                swap(a, b);

            if(~a)
                cout << a << " " << b << endl;
            else if(n & 1)
                cout << "Spinster Number.\n";
            else
                cout << "Bachelor Number.\n";
        }
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    init();
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}