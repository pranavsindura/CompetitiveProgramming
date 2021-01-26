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

int check(pii a, pii b)
{
    if(a.second < b.first)
        return -1;
    else if(a.first > b.second)
        return 1;
    else
        return 0;
}
int main()
{
    FASTIO;
    int q;
    cin>>q;
    while(q--)
    {
        int n, s;
        cin>>n>>s;
        bool f = true;
        int t=0;
        pii temp = mp(s, s);
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            int time = a-t;
            pii temp2 = mp(temp.first-time, temp.second+time);
            if(check(temp2, mp(b,c)) == 0)
            {
                temp = mp(max(temp2.first, b), min(temp2.second, c));
            }
            else
                f = false;
            t = a;
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}