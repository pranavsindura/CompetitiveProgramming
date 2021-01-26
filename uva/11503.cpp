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
void make_set(int v, vector<int> &p, vector<int> &s)
{
    p[v] = v;
    s[v] = 1;
}
int find_set(int v, vector<int> &p)
{
    return v == p[v] ? v : p[v] = find_set(p[v], p);
}
bool union_set(int a, int b, vector<int> &p, vector<int> &s)
{
    a = find_set(a, p), b = find_set(b, p);
    if(a != b)
    {
        if(s[b] > s[a])
            swap(a, b);
        p[b] = a;
        s[a] += s[b];
        return true;
    }
    else
        return false;
}
int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        set<string> name;
        map<string, int> num;
        int c = 0;
        vector<int> p(100005), s(100005);
        for(int i = 0; i < sz(p); i++)
            make_set(i, p, s);
        for(int i = 0; i < n; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if(name.find(s1) == name.end())
            {
                name.insert(s1);
                num[s1] = ++c;
            }
            if(name.find(s2) == name.end())
            {
                name.insert(s2);
                num[s2] = ++c;
            }
            union_set(num[s1], num[s2], p, s);
            int par = find_set(num[s1], p);
            cout << s[par] << endl;
        }
    }
    return 0;
}