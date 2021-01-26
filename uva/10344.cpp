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
const double PI = acos(-1.0);
using namespace std;

int calc(int a, int b, int op)
{
    if(op == 1)
        return a + b;
    else if(op == 2)
        return a - b;
    else
        return a * b;
}

string ops(int op)
{
    if(op == 1)
        return " + ";
    else if(op == 2)
        return " - ";
    else
        return " * ";
}

bool bfs(vector<int> arr)
{
    queue<pii> q;
    q.push(mp(arr[0], 0));
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        if(u.ss == sz(arr) - 1)
        {
            if(u.ff == 23)
                return true;
        }
        else
        {
            q.push(mp(u.ff + arr[u.ss + 1], u.ss + 1));
            q.push(mp(u.ff - arr[u.ss + 1], u.ss + 1));
            q.push(mp(u.ff * arr[u.ss + 1], u.ss + 1));
        }

    }
    return false;
}

void cp(vector<int> arr)
{
    bool ok = false;
    do
    {
        ok = ok || bfs(arr);
    }
    while(next_permutation(all(arr)));
    cout << (ok ? "Possible\n" : "Impossible\n");
}

int main()
{
    FASTIO;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    while(a || b || c || d || e)
    {
        vector<int> arr = {a, b, c, d, e};
        sort(all(arr));
        cp(arr);
        cin >> a >> b >> c >> d >> e;
    }
    return 0;
}