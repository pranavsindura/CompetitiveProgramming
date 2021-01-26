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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

bool check(string x)
{
    for(int i=0;i<ln(x);i++)
    {
        if(x[i] != x[ln(x)-i-1])
            return false;
    }
    return true;
}

int main()
{
    FASTIO;
    int n,m;
    cin>>n>>m;
    vector<string> arr(n);
    for(string &x: arr)
        cin>>x;
    string res;
    vector<string> palin;
    vector<bool> done(n, false);
    for(int i=0;i<n;i++)
    {   
        if(check(arr[i]))
        {
            res += arr[i];
            done[i] = true;
            break;
        }
    }
    vector<pair<string,string>> p;
    for(int i=0;i<n;i++)
    {
        if(done[i])
            continue;
        done[i] = true;
        string temp = arr[i];
        reverse(all(temp));
        for(int j=0;j<n;j++)
        {
            if(done[j])
                continue;
            if(temp == arr[j])
                p.pb(mp(arr[i], arr[j])), done[j]=true;

        }
    }
    for(int i=0;i<sz(p);i++)
        res = p[i].first+res+p[i].second;
    cout<<ln(res)<<endl<<res;
    return 0;
}