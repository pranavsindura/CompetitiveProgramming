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
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> peg(n, 0);
        int num = 1;
        while(true)
        {
            bool place = false;
            for(int i = 0; i < n; i++)
            {
                if(!peg[i] || ((peg[i] + num) == ((int)sqrt(peg[i] + num) * (int)sqrt(peg[i] + num))))
                {
                    peg[i] = num;
                    place = true;
                    break;
                }
            }
            if(place)
                num++;
            else
                break;
        }
        cout<<num-1<<endl;
    }
    return 0;
}