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
#define dbg(x) cout<<#x<<": "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;

void cp()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;
    map<int, int> mp;
    for(int x : a)
        mp[x]++;
    bool ok = true;
    for(int i = n-1; i >= 0; i--)
    {
        int diff = b[i] - a[i];
        if(diff < 0)
        {
        	mp[a[i]]--;
            if(mp[-1])
            {
                //ok
                
            }
            else
                ok = false;
        }
        else if(diff > 0)
        {
        	mp[a[i]]--;
            if(mp[1])
            {
                //ok
                
            }
            else
                ok = false;
        }
        else
        	mp[a[i]]--;
    }
    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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