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
const int MAXN = 1e6 + 5;

set<int> arr;
multiset<int> gaps;

void add(int val)
{
    if(arr.empty())
        arr.insert(val);
    else if(sz(arr) == 1)
        arr.insert(val), gaps.insert(*arr.rbegin() - *arr.begin());
    else
    {
        auto nx = arr.upper_bound(val);
        if(nx == arr.end())
        {
            int prev = *arr.rbegin();
            arr.insert(val);
            gaps.insert(val - prev);
        }
        else if(nx == arr.begin())
        {
            int first = *arr.begin();
            arr.insert(val);
            gaps.insert(first - val);
        }
        else
        {
            auto prev = nx;
            prev--;
            int currgap = *nx - *prev;
            gaps.erase(gaps.lower_bound(currgap));
            gaps.insert(*nx - val);
            gaps.insert(val - *prev);
            arr.insert(val);
        }
    }
}

void remove(int val)
{
    if(sz(arr) <= 2)
    {
        arr.erase(val);
        gaps.clear();
    }
    else
    {
        auto nx = arr.upper_bound(val);
        if(nx == arr.end())
        {
            arr.erase(val);
            int prev = *arr.rbegin();
            gaps.erase(gaps.lower_bound(val - prev));
        }
        else
        {
            auto me = nx;
            me--;
            if(me == arr.begin())
            {
                int currgap = *nx - val;
                gaps.erase(gaps.lower_bound(currgap));
                arr.erase(val);
            }
            else
            {
                auto prev = me;
                prev--;
                int gap1 = *nx - val;
                int gap2 = val - *prev;
                int gap3 = *nx - *prev;
                gaps.erase(gaps.lower_bound(gap1));
                gaps.erase(gaps.lower_bound(gap2));
                arr.erase(val);
                gaps.insert(gap3);
            }
        }
    }
}

int get()
{
    if(gaps.empty())
        return 0;
    int mx = *arr.rbegin() - *arr.begin() - *gaps.rbegin();
    return mx;
}

void cp()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0, x = 0; i < n; i++)
        cin >> x, add(x);
    cout << get() << endl;
    while(q--)
    {
        int t, x;
        cin >> t >> x;

        if(t)
            add(x);
        else
            remove(x);

        cout << get() << endl;
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