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
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;

    map<int, int> freq;
    for(int x : arr)
        freq[x]++;
    set<int> G;
    for(auto x : freq)
        if(x.ss > 1)
            G.insert(x.ff);
    bool can = false;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0) continue;
        if(freq[arr[i] - 1] > 0) continue;
        freq[arr[i]]--;
        if(freq[arr[i]] == 1) G.erase(arr[i]);
        if(G.empty()) can = true;
        freq[arr[i]]++;
        if(freq[arr[i]] > 1) G.insert(arr[i]);
    }
    can &= freq[0] <= 1;

    if(!can)
    {
        cout << "cslnb\n";
        return;
    }

    sort(all(arr));

    int total = 0;
    int make = 0;
    n = sz(arr);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= make)
            total = (total + arr[i] - make) % 2, make++;
    }

    cout << (total ? "sjfnb\n" : "cslnb\n");
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

