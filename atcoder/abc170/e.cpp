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
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 2e5 + 5;

vector<int> rating, pos;
struct comp
{
    const bool operator()(const int &a, const int &b)const
    {
        if(rating[a] != rating[b])
            return rating[a] < rating[b];
        else
            return a < b;
    }
};
vector<set<int, comp>> arr(MAXN);


void cp()
{
    int n, q;
    cin >> n >> q;
    rating.resize(n), pos.resize(n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        b--;
        rating[i] = a;
        arr[b].insert(i);
        pos[i] = b;
    }
    set<int, comp> mnrating;
    for(int i = 0; i < MAXN; i++)
        if(!arr[i].empty())
            mnrating.insert(*arr[i].rbegin());

    while(q--)
    {
        int c, d;
        cin >> c >> d;
        c--, d--;
        if(pos[c] != d)
        {
            // move child c from pos[c] to d
            if(*arr[pos[c]].rbegin() == c)
                mnrating.erase(c);

            arr[pos[c]].erase(c);
            if(!arr[pos[c]].empty())
                mnrating.insert(*arr[pos[c]].rbegin());

            pos[c] = d;
            // needs to go to d
            if(!arr[d].empty())
                mnrating.erase(*arr[d].rbegin());
            arr[d].insert(c);
            mnrating.insert(*arr[d].rbegin());
        }
        cout << rating[*mnrating.begin()] << endl;
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