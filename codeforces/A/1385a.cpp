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

void cp()
{
    int x, y, z;
    cin >> x >> y >> z;
    if(x == y || y == z || x == z)
    {
        int a[] = {x, y, z};
        sort(a, a + 3);
        a[1] = 1;
        sort(a, a + 3);
        do
        {
            if(max(a[0], a[1]) == x && max(a[0], a[2]) == y && max(a[1], a[2]) == z)
            {
                cout << "YES\n";
                cout << a[0] << " " << a[1] << " " << a[2] << endl;
                return;
            }
        }
        while(next_permutation(a, a + 3));
        cout << "NO\n";
    }

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