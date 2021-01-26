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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define nl cout<<endl;
#define rep(i, x) for(int i=0;i<sz(x);i++)
const double PI = acos(-1.0);
using namespace std;

typedef vector<int> row;
typedef vector<row> matrix;

matrix zero(int n, int m)
{
    return matrix(n, row(m, 0));
}

matrix identity(int n, int m)
{
    matrix x = zero(n, m);
    for(int i = 0; i < n; i++)
        x[i][i] = 1;
    return x;

}

int matrixTrace(matrix &x)
{
    int sum = 0;
    for(int i = 0; i < sz(x); i++)
        sum += x[i][i];
    return sum;
}

matrix rotate(matrix &a)
{
    matrix x = zero(sz(a[0]), sz(a));
    for(int i = 0; i < sz(a); i++)
    {
        for(int j = 0; j < sz(a[0]); j++)
        {
            x[j][sz(a) - i - 1] = a[i][j];
        }
    }
    return x;
}

matrix reflect(matrix &a)
{
    matrix x = zero(sz(a), sz(a[0]));
    for(int i = 0; i < sz(a); i++)
    {
        for(int j = 0; j < sz(a[0]); j++)
        {
            x[i][sz(a[0]) - j - 1] = a[i][j];
        }
    }
    return x;
}

matrix add(matrix &a, matrix &b)
{
    matrix x = zero(sz(a), sz(a[0]));
    for(int i = 0; i < sz(a); i++)
    {
        for(int j = 0; j < sz(a[0]); j++)
        {
            x[i][j] = a[i][j] + b[i][j];
        }
    }
    return x;
}

matrix addIdentity(const matrix &a)
{
    matrix x = a;
    for(int i = 0; i < sz(a); i++)
        x[i][i]++;
    return x;
}

matrix mul(const matrix &a, const matrix &b)
{
    int n = a.size(), m = a[0].size(), z = b[0].size();
    matrix x = zero(n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < z; j++)
            for(int k = 0; k < m; k++)
                x[i][j] += a[i][k] * b[k][j];
    return x;
}

matrix power(matrix a, ll k)
{
    if(k == 0)
        return identity(sz(a), sz(a[0]));
    else if(k & 1)
        return multiply(a, power(a, k - 1));
    else
        return power(multiply(a, a), k / 2);
}

matrix powerSum(matrix a, ll k)
{
    if(k == 0)
        return zero(sz(a), sz(a[0]));
    else if(k & 1)
        return multiply(a, addIdentity(powerSum(a, k - 1)));
    else
        return multiply(addIdentity(power(a, k / 2)), powerSum(a, k / 2));
}

void print(matrix x)
{
    for(row r : x)
    {
        for(int e : r)
            cout << e << " ";
        nl;
    }
}

void cp()
{
    matrix p =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    matrix q =
    {
        {-1, -2, -3},
        {-4, -5, -6},
        {-7, -8, -9}
    };
    print(powerSum(p, 5));
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin>>t;
    while(t--)
    {
        cp();
    }
    return 0;
}