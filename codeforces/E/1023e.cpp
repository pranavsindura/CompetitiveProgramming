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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

void cp()
{
    int n;
    cin >> n;

    pi x_bound = {1, n};
    pi y_bound = {1, n};

    auto valid = [&](int nx, int ny)
    {
        return (nx >= x_bound.ff && nx <= x_bound.ss && ny >= y_bound.ff && ny <= y_bound.ss);
    };
    int cnt = 0;
    auto query = [&](int r1, int c1, int r2, int c2, bool type)
    {
        if((valid(r1, c1) || type) && (valid(r2, c2) || !type))
        {
            cnt++;
            cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
            cout.flush();
            string res;
            cin >> res;
            if(res == "BAD")
                exit(0);
            return (res == "YES");
        }
        else
            return false;
    };

    string ans;
    // Reach diagonal
    int x = 1, y = 1;
    while(x + y != n + 1)
    {
        if(query(x, y + 1, n, n, 0))
            ans += 'R', y++;
        else if(query(x + 1, y, n, n, 0))
            ans += 'D', x++;
        else
            exit(0);
    }
    // I have reached diagonal
    // Find path from (x,y) to (n,n)
    int a = x, b = y;
    x = n, y = n;
    x_bound = {a, n}, y_bound = {b, n};
    string temp = ans;

    string ans2;

    while(!temp.empty())
    {
        if(temp.back() == 'D')
            a--;
        else
            b--;
        temp.pop_back();
        if(query(a, b, x - 1, y, 1))
            ans2 += 'D', x--;
        else if(query(a, b, x, y - 1, 1))
            ans2 += 'R', y--;
        else
            exit(0);
    }

    reverse(all(ans2));
    cout << "! " << ans << ans2 << endl;
    cout.flush();
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