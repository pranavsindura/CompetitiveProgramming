#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
#define mod 1000000007
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n,k;
    cin>>n>>k;
    map<string, int> hash, ind;
    vector<string> arr(n);
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        hash[arr[i]]++;
    }
    sort(all(arr));
    ll count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            string f="";
            for(int a=0;a<k;a++)
            {
                string x;
                x += arr[i][a];
                x += arr[j][a];
                if(arr[i][a] == arr[j][a])
                    f += arr[i][a];
                else if(x == "SE" || x == "ES")
                    f += "T";
                else if(x == "TE" || x == "ET")
                    f += "S";
                else if(x == "ST" || x == "TS")
                    f += "E";
            }
            count += hash[f];
        }
    }
    cout<<count/3LL;
    return 0;
}