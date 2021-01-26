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
    string s;
    cin >> s;
    map<int, int> freq;
    for(char x : s)
        freq[x - '0']++;

    bool ok = false;
    if(ln(s) <= 5)
    {
        string t = s;
        sort(all(t));
        do
        {
            int num = stoi(t);
            ok |= num % 8 == 0;
        }
        while(next_permutation(all(t)));
    }

    for(int i = 0; i < 1000; i += 8)
    {
        map<int, int> need;
        int temp = i;
        for(int j = 0; j < 3; j++)
            need[temp % 10]++, temp /= 10;
        bool can = true;
        for(auto x : need)
            can &= freq[x.ff] >= x.ss;
        ok |= can;
    }
    cout << (ok ? "Yes\n" : "No\n");
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