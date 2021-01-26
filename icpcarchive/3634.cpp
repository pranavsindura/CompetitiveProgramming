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

void cp()
{
    int q, cnt = 0;
    cin >> q;
    stack<int> st;
    map<int, set<int>> mp1;
    map<set<int>, int> mp2;
    while(q--)
    {
        string op;
        cin >> op;
        if(op == "PUSH")
        {
            if(mp2.count(set<int>()))
                st.push(mp2[set<int>()]);
            else
                mp2[set<int>()] = cnt, mp1[cnt] = set<int>(), st.push(cnt), cnt++;
        }
        else if(op == "DUP")
        {
            st.push(st.top());
        }
        else if(op == "UNION")
        {
            set<int> a = mp1[st.top()];
            st.pop();
            set<int> b = mp1[st.top()];
            st.pop();

            set<int> res;
            set_union(all(a), all(b), inserter(res, begin(res)));

            if(mp2.count(res))
                st.push(mp2[res]);
            else
                mp2[res] = cnt, mp1[cnt] = res, st.push(cnt), cnt++;
        }
        else if(op == "ADD")
        {
            int a_ref = st.top();
            st.pop();
            set<int> b = mp1[st.top()];
            st.pop();

            b.insert(a_ref);

            if(mp2.count(b))
                st.push(mp2[b]);
            else
                mp2[b] = cnt, mp1[cnt] = b, st.push(cnt), cnt++;
        }
        else
        {
            set<int> a = mp1[st.top()];
            st.pop();
            set<int> b = mp1[st.top()];
            st.pop();

            set<int> res;
            set_intersection(all(a), all(b), inserter(res, begin(res)));

            if(mp2.count(res))
                st.push(mp2[res]);
            else
                mp2[res] = cnt, mp1[cnt] = res, st.push(cnt), cnt++;
        }
        cout << sz(mp1[st.top()]) << endl;
    }
    cout << "***\n";
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}