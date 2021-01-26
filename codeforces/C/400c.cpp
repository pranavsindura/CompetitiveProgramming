#include<bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>
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
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

void clockwise(int &i, int &j, int &n, int &m)
{
    int x = j, y = n - i - 1;
    swap(n, m);
    i = x, j = y;
}
void anti_clockwise(int &i, int &j, int &n, int &m)
{
    int x = m - j - 1, y = i;
    swap(n, m);
    i = x, j = y;
}
void horizontal_rotate(int &i, int &j, int &n, int &m)
{
    int x = i, y = m - j - 1;
    i = x, j = y;
}

void cp()
{
    int n, m, x, y, z, p;
    cin >> n >> m >> x >> y >> z >> p;
    x = x % 4;
    y = y % 2;
    z = z % 4;
    vector<pi> arr(p);
    for(int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int temp_n = n, temp_m = m;
        for(int j = 0; j < x; j++)
        {
            clockwise(a, b, temp_n, temp_m);
        }
        for(int j = 0; j < y; j++)
        {
            horizontal_rotate(a, b, temp_n, temp_m);
        }
        for(int j = 0; j < z; j++)
        {
            anti_clockwise(a, b, temp_n, temp_m);
        }
        arr[i] = {a + 1, b + 1};
    }
    for(pi a : arr)
        cout << a.ff << " " << a.ss << endl;
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