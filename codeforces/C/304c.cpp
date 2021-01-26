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

int main()
{
    FASTIO;
    int n;
    cin >> n;
    //no solution when n is even
    // -1
    vector<int> a, c;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        a.pb(i);
        c.pb((i + i) % n);

        s.insert((i + i) % n);
    }
    if(sz(s) != n)
        cout << -1;
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++)
        {
            cout << c[i] << " ";
        }
    }
    return 0;
}