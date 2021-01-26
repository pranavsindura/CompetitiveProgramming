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

void cp()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    string pat;
    cin >> pat;

    vector<int> failure(ln(pat));
    for(int i = 1, k = 0; i < ln(pat); i++)
    {
        while(k && pat[i] != pat[k])
            k = failure[k - 1];
        if(pat[i] == pat[k])
            k++;
        failure[i] = k;
    }

    auto match = [&](int i, int k)
    {
        // try to add arr[i] to the pattern, so far of length k
        if(pat[k] == 'G')
            return arr[i] > arr[i - 1];
        else if(pat[k] == 'L')
            return arr[i] < arr[i - 1];
        else
            return arr[i] == arr[i - 1];
    };

    bool ok = false;
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k && !match(i, k))
            k = failure[k - 1];
        if(match(i, k))
            k++;
        if(k == ln(pat))
            ok = true, k = failure[k - 1];
    }
    cout << (ok ? "YES\n" : "NO\n");
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