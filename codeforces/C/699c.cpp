#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;
int dp[101][3][101];
int n;
int rec(vector<int> &arr, int i, int last, int rest)
{
    if(i == n)
        return rest;
    int ret = dp[i][last][rest];
    if(ret != -1)
        return ret;
    ret = INT_MAX;
    if(last == 0)
    {
        if(arr[i] == 0)
        {
            ret = min(ret, rec(arr, i + 1, 0, rest + 1));
        }
        else if(arr[i] == 1)
        {
            ret = min(ret, rec(arr, i + 1, 1, rest));
        }
        else if(arr[i] == 2)
        {
            ret = min(ret, rec(arr, i + 1, 2, rest));
        }
        else
        {
            ret = min(
            {
                ret, rec(arr, i + 1, 1, rest),
                rec(arr, i + 1, 2, rest)
            });
        }
    }
    else if(last == 1)
    {
        if(arr[i] == 0 || arr[i] == 1)
        {
            ret = min(ret, rec(arr, i + 1, 0, rest + 1));
        }
        else
        {
            ret = min(ret, rec(arr, i + 1, 2, rest));
        }
    }
    else
    {
        if(arr[i] == 0 || arr[i] == 2)
        {
            ret = min(ret, rec(arr, i + 1, 0, rest + 1));
        }
        else
        {
            ret = min(ret, rec(arr, i + 1, 1, rest));
        }
    }
    return dp[i][last][rest] = ret;
}

int main()
{
    FASTIO;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
            dp[i][0][j] = -1, dp[i][1][j] = -1, dp[i][2][j] = -1;

    }
    int a = rec(arr, 0, 0, 0);
    cout << a;
}