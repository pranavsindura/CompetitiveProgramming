#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

void pf(int n, map<int, int> &f)
{
    int temp = n;
    while(temp % 2 == 0)
    {
        f[2]++;
        temp /= 2;
    }
    for(int i = 3; i * i <= n; i+=2)
    {
        while(temp % i == 0)
        {
            f[i]++;
            temp /= i;
        }
    }
    if(temp > 2)
        f[temp]++;
    // cout << n << endl;
    // for(auto x : f)
    //     cout << x.ff << " " << x.ss << endl;
}

int main()
{
    FASTIO;
    int a, b;
    cin >> a >> b;
    map<int, int> fa, fb;
    pf(a, fa);
    pf(b, fb);
    int count = 0;
    count += abs(fa[2] - fb[2]);
    count += abs(fa[3] - fb[3]);
    count += abs(fa[5] - fb[5]);
    for(auto x : fa)
    {
        if(x.ff == 2 || x.ff == 3 || x.ff == 5)
            continue;
        if(!fb[x.ff])
        {
            count = -1;
        }
    }
    for(auto x : fb)
    {
        if(x.ff == 2 || x.ff == 3 || x.ff == 5)
            continue;
        if(!fa[x.ff])
        {
            count = -1;
        }
    }
    cout << count;
    return 0;
}