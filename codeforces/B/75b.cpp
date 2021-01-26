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
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double PI = acos(-1.0);

void cp()
{
    string my_name;
    cin >> my_name;
    int n;
    cin >> n;
    map<string, int> distinct;
    map<pair<string, string>, int> priority;
    while(n--)
    {
        vector<string> query;
        string q;
        int count = 0;
        while(true)
        {
            cin >> q;
            count++;
            query.pb(q);
            if((q == "post" || q == "wall") && count >= 4)
                break;
        }
        string a = query[0];
        string b = query[sz(query) - 2];
        b.pop_back();
        b.pop_back();
        distinct[a]++;
        distinct[b]++;
        if(query[1] == "posted")
        {
            priority[ {a, b} ] += 15;
            priority[ {b, a} ] += 15;
        }
        else if(query[1] == "commented")
        {
            priority[ {a, b} ] += 10;
            priority[ {b, a} ] += 10;
        }
        else
        {
            priority[ {a, b} ] += 5;
            priority[ {b, a} ] += 5;
        }
    }
    vector<string> names;
    for(auto x : distinct)
    {
        if(x.ff != my_name)
            names.pb(x.ff);
    }
    sort(all(names), [&](string a, string b)
    {
        int pa = priority[ {my_name, a}];
        int pb = priority[ {my_name, b}];
        if(pa == pb)
        {
            return a < b;
        }
        else
            return pa > pb;
    });
    for(string x : names)
        cout << x << endl;
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