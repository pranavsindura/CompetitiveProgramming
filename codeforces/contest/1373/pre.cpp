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
#define dbg(x) cout << #x << ": " << x << endl
#define clr(x,v) memset(x, v, sizeof(x))
#define dblout(x) cout << setprecision(x) << fixed;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const int MAXN = 1e9 + 5;

int dig_sum(int x)
{
    int sum = 0;
    while(x)
        sum += x % 10, x /= 10;
    return sum;
}

int save[156][10];

void cp()
{
    for(int i = 0; i <= 155; i++)
        for(int k = 0; k <= 9; k++)
            save[i][k] = INT_MAX;
    for(int i = 0; i < MAXN; i++)
    {
        int sum = dig_sum(i);
        for(int k = 1; k <= 9; k++)
        {
            sum += dig_sum(i + k);
            if(sum <= 150)
                save[sum][k] = min(save[sum][k], i);
        }
        // if(i % 10000000 == 0)
        //     dbg(i);
    }
    // dbg("done");
    cout << "{\n";
    for(int i = 0; i <= 155; i++)
    {
        cout << "{";
        for(int k = 0; k <= 9; k++)
        {
            if(save[i][k] == INT_MAX)
                save[i][k] = -1;
            cout << save[i][k];
            if(k < 9)
                cout << ", ";
        }
        cout << "}";
        if(i < 155)
            cout << ",";
        cout << endl;
    }
    cout << "}\n";
}

int main()
{
    // FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}

/*
// greedy, k = 0
    cout << "k = 0\n";
    for(int i = 1; i <= 150; i++)
    {
        string num;
        int sum = i;
        while(sum > 9)
            num += '9', sum -= 9;
        if(sum)
            num += char(48 + sum);
        reverse(all(num));
        cout << i << ": " << num << endl;
    }
*/