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

vector<vector<int>> rota(vector<vector<int>> arr, int times)
{
    vector<vector<int>> res = arr;
    int n = sz(res);
    for(int t = 0; t < times; t++)
    {
        vector<vector<int>> rot(n, vector<int>(n));
        //col
        for(int i = 0; i < n; i++)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                rot[i][n - j - 1] = res[j][i];
            }
        }
        res = rot;
    }
    return res;
}

vector<vector<int>> reflect(vector<vector<int>> arr)
{
    vector<vector<int>> res = arr;
    int n = sz(res);
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n / 2; i++)
            swap(res[i][j], res[n - i - 1][j]);
    }
    return res;
}
int test;
void cp(int n)
{
    vector<vector<int>> a, b;
    for(int i = 0; i < n; i++)
    {
        string p, q;
        cin >> p >> q;
        vector<int> puta(n), putb(n);
        for(int j = 0; j < n; j++)
            puta[j] = (p[j] == 'X'), putb[j] = (q[j] == 'X');
        a.pb(puta), b.pb(putb);
    }
    cout << "Pattern " << test << " was ";
    if(a == b)
    {
        cout << "preserved.";
    }
    else if(rota(a, 1) == b)
    {
        cout << "rotated 90 degrees.";
    }
    else if(rota(a, 2) == b)
    {
        cout << "rotated 180 degrees.";
    }
    else if(rota(a, 3) == b)
    {
        cout << "rotated 270 degrees.";
    }
    else if(reflect(a) == b)
    {
        cout << "reflected vertically.";
    }
    else if(rota(reflect(a), 1) == b)
    {
        cout << "reflected vertically and rotated 90 degrees.";
    }
    else if(rota(reflect(a), 2) == b)
    {
        cout << "reflected vertically and rotated 180 degrees.";
    }
    else if(rota(reflect(a), 3) == b)
    {
        cout << "reflected vertically and rotated 270 degrees.";
    }
    else
    {
        cout << "improperly transformed.";
    }
    cout << endl;
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    while(cin >> t)
    {
        test++;
        cp(t);
    }
    return 0;
}