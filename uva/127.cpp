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
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);

bool match(string a, string b)
{
    return (a[0] == b[0] || a[1] == b[1]);
}

int main()
{
    FASTIO;
    string s;
    while(true)
    {
        cin >> s;
        if(s == "#")
            break;
        vector<stack<string>> piles(1);
        piles[0].push(s);
        for(int card = 1; card < 52; card++)
        {
            cin >> s;
            stack<string> st;
            st.push(s);
            piles.pb(st);
            bool any = true;
            while(any)
            {
                any = false;
                for(int i = 0; i < sz(piles); i++)
                {
                    if(i - 3 >= 0 && match(piles[i - 3].top(), piles[i].top()))
                    {
                        any = true;
                        string m = piles[i].top();
                        piles[i].pop();
                        piles[i - 3].push(m);
                        if(piles[i].empty())
                        {
                            piles.erase(begin(piles) + i);
                        }
                        break;
                    }
                    if(i - 1 >= 0 && match(piles[i - 1].top(), piles[i].top()))
                    {
                        any = true;
                        string m = piles[i].top();
                        piles[i].pop();
                        piles[i - 1].push(m);
                        if(piles[i].empty())
                        {
                            piles.erase(begin(piles) + i);
                        }
                        break;
                    }
                }
            }
        }
        cout << sz(piles) << (sz(piles) == 1 ? " pile" : " piles") << " remaining:";
        for(auto it : piles)
            cout << " " << sz(it);
        nl;
    }
    return 0;
}