#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<": "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e6 + 5;

class BobTrouble
{
public:
    int minSupers(vector <string> name, vector <string> bossName)
    {
        int n = sz(name);
        queue<string> q;
        set<string> exist;
        q.push("*");
        while(!q.empty())
        {
            string u = q.front();
            q.pop();
            for(int i = 0; i < n; i++)
            {
                if(bossName[i] == u && exist.find(name[i]) == exist.end())
                    q.push(name[i]), exist.insert(name[i]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(exist.find(name[i]) == exist.end())
                return -1;
        }
        exist.clear();
        for(int i = 0; i < n; i++)
            exist.insert(bossName[i]);
        return sz(exist) - 1;
    }
};

// int main()
// {
//     FASTIO;
//     int t;
//     t = 1;
//     cin >> t;
//     while(t--)
//     {
//         cp();
//     }
//     return 0;
// }