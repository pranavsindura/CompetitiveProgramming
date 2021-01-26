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
    vector<int> a(3), b(3);
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    auto win = [&](int x, int y)
    {
        // 0 -> rock, 1->scissor, 2->paper
        return y == (x + 1) % 3;
    };

    int mx = INT_MIN, mn = INT_MAX;
    vector<int> perm1 = {0, 1, 2}, perm2 = perm1;

    do
    {
        do
        {
            vector<int> p = {a[perm1[0]], a[perm1[1]], a[perm1[2]]};
            vector<int> q = {b[perm2[0]], b[perm2[1]], b[perm2[2]]};

            int wins = 0,i = 0, j = 0;

            while(i < 3 && j < 3)
            {
                int game = min(p[i], q[j]);
                wins += game * win(perm1[i], perm2[j]);
                p[i] -= game, q[j] -= game;

                if(!p[i])
                    i++;
                if(!q[j])
                    j++;
            }

            mn = min(mn, wins);
            mx = max(mx, wins);
        }
        while(next_permutation(all(perm2)));
    }
    while(next_permutation(all(perm1)));
    
    cout << mn << " " << mx << endl;
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