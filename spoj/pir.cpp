#include<bits/stdc++.h>
#define ll long long int
#define ld long double
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
// http://mathforum.org/dr.math/faq/formulas/faq.irreg.tetrahedron.html

ll det(vector<vector<ll>> mat, int n)
{
    if(n == 2)
    {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    else
    {
        vector<vector<ll>> submat(n - 1, vector<ll>(n - 1, 0));
        ll ans = 0;
        for(int c = 0; c < n; c++)
        {
            int col_pos = 0;
            for(int i = 1; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(j == c)
                        continue;
                    submat[i - 1][col_pos % (n - 1)] = mat[i][j];
                    col_pos++;
                }
            }
            int sg = (c % 2 ? -1 : +1);
            ans += mat[0][c] * sg * det(submat, n - 1);
        }
        return ans;
    }
}

void cp()
{
    // AB,  AC,  AD,  BC,  BD,  CD
    // d12, d13, d14, d23, d24, d34
    ll d12, d13, d14, d23, d24, d34;
    cin >> d12 >> d13 >> d14 >> d23 >> d24 >> d34;
    d12 *= d12;
    d13 *= d13;
    d14 *= d14;
    d23 *= d23;
    d24 *= d24;
    d34 *= d34;
    vector<vector<ll>> mat =
    {
        {0, d12, d13, d14, 1},
        {d12, 0, d23, d24, 1},
        {d13, d23, 0, d34, 1},
        {d14, d24, d34, 0, 1},
        {1,   1,   1,   1, 0}
    };
    // 288 * v^2 = |mat|
    double d = 1.0 * det(mat, 5);
    double vol_square = d / 288.0;
    double vol = sqrt(vol_square);
    cout << setprecision(4) << fixed << vol << endl;
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