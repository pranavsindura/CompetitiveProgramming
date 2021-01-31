#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pii pair<int, int>
#define inf 1e9
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define maxn 100000+5
#define ff first
#define ss second
#define sz size
#define lnt length
#define here(x) cout << #x << " is " << x << endl;
#define setv(x, v) memset(x, v, sizeof(x))
#define prec(x) cout << fixed << setprecision(x);
#define fio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve()
{
    string str, s1 = "Impostor", s2 = "Crewmate";
    cin >> str;
    int cnt = 0;
    for(int i = 0; i <= str.lnt() - 8; i++)
    {
        if(str[i] == 'I')
        {
            bool f = true;
            for(int j = i; j < i + 8; j++)
            {
                if(s1[j - i] != str[j])
                {
                    f = false;
                    break;
                }
            }
            if(f)
                cnt++;
        }
    }
    // here(cnt);
    if(cnt)
        cout << "There is " << cnt << " Impostor among us";
    else
        cout << "Clear";
}

int main()
{
    fio;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}