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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int n,k;
    cin>>n>>k;
    int mx = (n/2)*(n/2) + ((n+1)/2)*((n+1)/2);
    if(k>mx)
        cout<<"NO";
    else
    {
        vector<vector<char>> arr(n, vector<char>(n,'S'));

        int c=0;
        bool need = (k!=c);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(need)
                {
                    if(i%2)
                    {
                        //floor
                        if(j%2)
                            arr[i][j]='L',c++;
                    }
                    else
                    {
                        //ceil
                        if(j%2==0)
                            arr[i][j]='L', c++;
                    }
                    // cout<<c<<": "<<i<<", "<<j<<endl;
                    if(c==k)
                        need=false;
                }
                else
                    break;
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}