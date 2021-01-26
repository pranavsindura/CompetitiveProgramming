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
const int MAXN = 1e6 + 5;

struct data
{
    int a, o, ind;
    data(){}
    data(int a, int o, int ind): a(a), o(o), ind(ind) {}
};

void cp()
{
    int n;
    cin >> n;
    vector<data> arr;
    ll total_a = 0, total_o = 0;
    for(int i = 0; i < 2 * n - 1; i++)
    {
        int a, o;
        cin >> a >> o;
        arr.pb(data(a, o, i + 1));
        total_a += a, total_o += o;
    }

    ll need_a = (total_a + 1) / 2, need_o = (total_o + 1) / 2;

    sort(all(arr), [](data a, data b)
    {
        return a.a < b.a;
    });

    ll odd = 0, even = 0;
    for(int i = 0; i < sz(arr); i++)
    {
        // considering 1based indexing
        if(i & 1)
            even += arr[i].o;
        else
            odd += arr[i].o;

    }

    if(odd >= need_o)
    {
        // take all odd indices
        cout << "YES\n";
        for(int i = 0; i < sz(arr); i++)
        {
            // considering 1based indexing
            if((i & 1) == 0)
            {
                cout << arr[i].ind << " ";
            }
        }
        cout << endl;
    }
    else //if(even >= need_o)
    {
        // take all even indices
        cout << "YES\n";
        for(int i = 0; i < sz(arr); i++)
        {
            // considering 1based indexing
            if(i & 1)
            {
                cout << arr[i].ind << " ";
            }
        }
        // take last box with most apples as well
        cout << arr.back().ind;
        cout << endl;
    }
    // No NO condition
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