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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool flag = true;
        int c = 0;
        while(flag)
        {
            flag = false;
            for(int i = n - 2; i >= 0; i--)
            {
                if(s[i] == 'A' && s[i + 1] == 'P')
                {
                    s[i + 1] = 'A';
                    flag = true;
                }
            }
            if(flag)
                c++;
        }
        cout << c << endl;
    }
    return 0;
}