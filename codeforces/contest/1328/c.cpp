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
#define dbg(x) cout<<#x<<" "<<x<<endl;
const double PI = acos(-1.0);
using namespace std;
vector<ll> sum(100005, 0);
void init()
{
    for(int i = 1; i < sz(sum); i++)
    {
        sum[i] = sum[i - 1] + i;
    }
}
int main()
{
    FASTIO;
    init();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> arr;
        vector<int> p, q;
        for(char x : s)
        {
            arr.pb(x - '0');
        }
        bool f = true;
        for(int i = 0; i < n; i++)
        {
            int a, b;
            if(f)
            {
                if(arr[i] == 0)
                    a = 0, b = 0;
                else if(arr[i] == 1){
                    a = 1, b = 0;
                    f = !f;
                }
                else{
                    a = 1, b = 1;
                }
            }
            else
            {
                if(arr[i] == 0)
                    a = 0, b = 0;
                else if(arr[i] == 1)
                    a = 0, b = 1;
                else
                    a = 0, b = 2;
            }

            p.pb(a), q.pb(b);
        }

        for(int x : p)
            cout << x;

        cout << endl;
        for(int x : q)
            cout << x;
        cout << endl;
    }
    return 0;
}