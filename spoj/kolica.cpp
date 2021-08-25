#include <bits/stdc++.h>
#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(), x.rend()
#define sz(x)     ((int)x.size())
#define ln(x)     ((int)x.length())
#define mp        make_pair
#define pb        push_back
#define ff        first
#define ss        second
#define endl      '\n'
#define dbg(x)    cout << #x << ": " << x << endl;
#define clr(x,v)  memset(x, v, sizeof(x));
#define fix(x)    cout << setprecision(x) << fixed;
#define FASTIO    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(st, ed)  uniform_int_distribution<int>(st, ed)(rng)

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;

const double PI = acos(-1.0);
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const int inf = 1e9;
const int MAXN = 1e5 + 5;

int collide(vector<int> A, vector<int> B)
{
    if(A[2] == B[2]) return inf;
    if(A[2] < 2 && B[2] < 2) // up down
    {
        if(A[2] == 0) // up
            return A[1] <= B[1] && A[0] == B[0] ? abs(A[1] - B[1]) : inf;
        else // down
            return A[1] >= B[1] && A[0] == B[0] ? abs(A[1] - B[1]) : inf;
    }
    else if(A[2] >= 2 && B[2] >= 2) // left right
    {
        if(A[2] == 2) // left
            return A[0] >= B[0] && A[1] == B[1] ? abs(A[0] - B[0]) : inf;
        else // right
            return A[0] <= B[0] && A[1] == B[1] ? abs(A[0] - B[0]) : inf;
    }
    else
    {
        int x, y;
        if(A[2] < 2) x = A[0];
        else y = A[1];
        if(B[2] < 2) x = B[0];
        else y = B[1];
        int dA = abs(x - A[0]) + abs(y - A[1]);
        int dB = abs(x - B[0]) + abs(y - B[1]);

        if(dA != dB) return inf;

        int does = 1;
        if(A[2] < 2) does &= collide(A, {x, y, 1 - A[2]}) != inf;
        else does &= collide(A, {x, y, 5 - A[2]}) != inf;
        if(B[2] < 2) does &= collide(B, {x, y, 1 - B[2]}) != inf;
        else does &= collide(B, {x, y, 5 - B[2]}) != inf;

        return does ? 2 * dA : inf;
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<vector<int>> p(n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        string dir;
        cin >> x >> y >> dir;
        p[i] = {x, y, 0};
        if(dir == "gore") p[i][2] = 0;
        else if(dir == "dolje") p[i][2] = 1;
        else if(dir == "lijevo") p[i][2] = 2;
        else p[i][2] = 3;
    }

    vector<int> dead(n);
    vector<int> time(n);
    for(int i = 0; i < n; i++)
    {
        time.assign(n, inf);
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(j != k && !dead[j] && !dead[k])
                    time[j] = min(time[j], collide(p[j], p[k]));
        int mn = *min_element(all(time));
        if(mn == inf) break;
        for(int j = 0; j < n; j++)
            if(time[j] == mn)
                dead[j] = 1;
    }
    bool any = false;
    for(int i = 0; i < n; i++)
        if(!dead[i]) cout << i + 1 << endl, any = true;
    if(!any) cout << "nema" << endl;
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
