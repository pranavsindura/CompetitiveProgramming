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

int dist2(pii a, pii b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main()
{
    FASTIO;
    int n, m, x, t;
    cin >> n >> m >> x;
    x *= x;
    vector<vector<char>> key(n, vector<char>(m, ' '));
    for(int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++)
        {
            key[i][j] = row[j];
        }
    }
    cin >> t;
    string s;
    cin >> s;
    int count = 0;
    vector<pii> coord_S;
    vector<int> dis(26, INT_MAX);
    vector<int> hash(26, 0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(key[i][j] == 'S')
                coord_S.push_back(make_pair(i+1, j+1));
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(key[i][j] == 'S')
                continue;
            hash[key[i][j]-'a']++;
            for(int k=0;k<sz(coord_S);k++)
            {
                dis[key[i][j]-'a'] = min(dis[key[i][j]-'a'], dist2(coord_S[k], make_pair(i+1, j+1)));
            }
        }
    }
    for(char i : s)
    {
        if(i <= 'z' && i >= 'a')
        {
            if(!hash[i-'a'])
            {
                count = -1;
                break;
            }
        }
        else if(i <= 'Z' && i >= 'A')
        {
            if(!coord_S.size())
            {
                count = -1;
                break;
            }
            char sm = char((i - 'A') + 97);
            if(dis[sm-'a'] == INT_MAX)
            {
                count = -1;
                break;
            }
            if(dis[sm-'a'] > x)
                count++;
        }
        else
        {
            count = -1;
            break;
        }
    }
    cout << count << endl;
    return 0;
}