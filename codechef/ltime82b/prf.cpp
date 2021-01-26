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

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int k, m;
        cin >> s >> k >> m;
        int hash[26] = {0};
        int count = 0;
        bool ok = true;
        bool del = false;
        for(int i = 0; i < ln(s); i++)
        {
            hash[s[i] - 'a']++;
            del = false;
            for(int j = 0; j < 26; j++)
            {
                if(hash[j] <= m)
                {
                    //good
                }
                else
                {
                    if(k)
                    {
                        hash[j]--, k--;
                        del = true;
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok)
            {
                if(!del)
                    count++;
            }
            else
                break;
        }
        cout << count << endl;
    }
    return 0;
}