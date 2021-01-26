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
    string s1, s2, s3, ans, a, b, c;
    cin >> s1 >> s2 >> s3;
    int hash[3] = {0};
    if(s1[1] == '>')
        hash[s1[0] - 'A']++;
    else
        hash[s1[2] - 'A']++;
    if(s2[1] == '>')
        hash[s2[0] - 'A']++;
    else
        hash[s2[2] - 'A']++;
    if(s3[1] == '>')
        hash[s3[0] - 'A']++;
    else
        hash[s3[2] - 'A']++;
    
    if(hash[0] == hash[1] || hash[1] == hash[2] || hash[2] == hash[0])
        cout << "Impossible";
    else
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(hash[j] == i)
                    cout << char(65+j);
            }
        }
    }
    return 0;
}