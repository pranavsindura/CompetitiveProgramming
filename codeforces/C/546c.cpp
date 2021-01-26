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
    int n, p, q;
    cin >> n;
    deque<int> a, b;
    cin >> p;
    for(int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        a.pb(x);
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        b.pb(x);
    }
    int win = 0, fight = 0;
    map<pair<deque<int>, deque<int>>, bool> m;
    while(true)
    {
        if(a.empty())
        {
            win = 2;
            break;
        }
        if(b.empty())
        {
            win = 1;
            break;
        }
        int x = a.front();
        int y = b.front();
        a.pop_front(), b.pop_front();
        if(x > y)
        {
            a.pb(y), a.pb(x);
        }
        else
        {
            b.pb(x), b.pb(y);
        }
        fight++;
        if(m[mp(a, b)])
        {
            win = 0;
            break;
        }
        m[mp(a, b)] = true;
    }
    if(!win)
        cout << -1;
    else
        cout << fight << " " << win;
    return 0;
}