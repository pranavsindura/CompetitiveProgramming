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

vector<int> col_ans(8);
vector<bool> col(8), row(8), d1(16), d2(16);
int solcount=0;
void solve(int c, int count)
{
    if(count == 8)
    {
        printf("%2d     ", ++solcount);
        for(int i = 0; i < 8; i++)
            cout << " " << col_ans[i];
        nl;
    }
    else
    {
        if(col[c])
        {
            solve(c + 1, count);
        }
        else
        {
            for(int r = 0; r < 8; r++)
            {
                if(!row[r] && !d1[r + c] && !d2[8 + r - c])
                {
                    col_ans[c] = r + 1;
                    row[r] = true;
                    d1[r + c] = true;
                    d2[8 + r - c] = true;
                    col[c] = true;
                    solve(c + 1, count + 1);
                    col[c] = false;
                    row[r] = false;
                    d1[r + c] = false;
                    d2[8 + r - c] = false;
                }
            }
        }
    }
}

void cp()
{
    int a, b;
    cin >> a >> b;
    a--, b--;
    col_ans[b] = a+1;
    col[b] = true;
    row[a] = true;
    d1[a + b] = true;
    d2[8 + a - b] = true;
    int count = 1;
    solve(0, count);
}

int main()
{
    int t, f=0;
    // t = 1;
    cin >> t;
    while(t--)
    {
        if(f)
            cout<<endl;
        f = 1;
        fill(all(col_ans), 0);
        fill(all(d1), false);
        fill(all(col), false);
        fill(all(row), false);
        fill(all(d2), false);
        solcount=0;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        cp();
    }
    return 0;
}