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
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
int freq[MAXN];
void cp()
{
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x, freq[x]++;
    set<int> more4, more2;
    for(int i = 1; i < MAXN; i++)
        if(freq[i] >= 4)
            more4.insert(i);
        else if(freq[i] >= 2)
            more2.insert(i);
    cin >> q;
    while(q--)
    {
        char t;
        int val;
        cin >> t >> val;

        if(t == '+')
        {
            freq[val]++;
            if(freq[val] >= 4)
            {
                more2.erase(val);
                more4.insert(val);
            }
            else if(freq[val] >= 2)
                more2.insert(val);
        }
        else
        {
            freq[val]--;
            if(freq[val] < 4)
            {
                more4.erase(val);
                if(freq[val] < 2)
                    more2.erase(val);
                else if(freq[val] >= 2)
                    more2.insert(val);
            }
        }
        
        bool ok = false;

        if(!more4.empty())
        {
            int pick = *more4.begin();
            more4.erase(more4.begin());
            freq[pick] -= 4;
            if(freq[pick] >= 4)
            {
                more4.insert(pick);
            }
            else if(freq[pick] >= 2)
            {
                more2.insert(pick);
            }

            if(!more4.empty())
            {
                // ok
                ok = true;
            }
            else
            {
                if(sz(more2) >= 2)
                    ok = true;
            }
            freq[pick] += 4;
            more2.erase(pick);
            more4.insert(pick);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
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