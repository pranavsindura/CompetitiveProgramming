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
#define endl '\n'
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<endl;
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " : " << a << endl;
    err(++it, args...);
}
const double PI = acos(-1.0);

bool valid(int a, int b, vector<int> &pos)
{
    if(a == b || pos[a] == pos[b])
        return false;
    else
        return true;
}

void move_onto(int a, int b, vector<stack<int>> &arr, vector<int> &pos)
{
    int pos_a = pos[a];
    int pos_b = pos[b];
    while(arr[pos_a].top() != a)
    {
        int x = arr[pos_a].top();
        arr[x].push(x);
        pos[x] = x;
        arr[pos_a].pop();
    }
    while(arr[pos_b].top() != b)
    {
        int x = arr[pos_b].top();
        arr[x].push(x);
        pos[x] = x;
        arr[pos_b].pop();
    }

    arr[pos_b].pop();
    pos[b] = b;
    arr[b].push(b);

    arr[b].push(a);
    arr[pos_a].pop();
    pos[a] = b;
}

void move_over(int a, int b, vector<stack<int>> &arr, vector<int> &pos)
{
    int pos_a = pos[a];
    int pos_b = pos[b];
    while(arr[pos_a].top() != a)
    {
        int x = arr[pos_a].top();
        arr[x].push(x);
        pos[x] = x;
        arr[pos_a].pop();
    }
    arr[pos_a].pop();
    arr[pos_b].push(a);
    pos[a] = pos_b;
}

void pile_onto(int a, int b, vector<stack<int>> &arr, vector<int> &pos)
{
    int pos_a = pos[a];
    int pos_b = pos[b];
    stack<int> temp;
    while(arr[pos_a].top() != a)
    {
        int x = arr[pos_a].top();
        temp.push(x);
        arr[pos_a].pop();
    }
    int xx = arr[pos_a].top();
    temp.push(xx);
    arr[pos_a].pop();
    while(arr[pos_b].top() != b)
    {
        int x = arr[pos_b].top();
        arr[x].push(x);
        pos[x] = x;
        arr[pos_b].pop();
    }

    arr[pos_b].pop();
    pos[b] = b;
    arr[b].push(b);

    while(!temp.empty())
    {
        int x = temp.top();
        arr[pos[b]].push(x);
        pos[x] = pos[b];
        temp.pop();
    }
}

void pile_over(int a, int b, vector<stack<int>> &arr, vector<int> &pos)
{
    stack<int> tmp;
    while(arr[pos[a]].top() != a)
    {
        tmp.push(arr[pos[a]].top());
        arr[pos[a]].pop();
    }

    tmp.push(arr[pos[a]].top());
    arr[pos[a]].pop();

    while(!tmp.empty())
    {
        arr[pos[b]].push(tmp.top());
        pos[tmp.top()] = pos[b];
        tmp.pop();
    }
}

void cp()
{
    int n;
    cin >> n;
    vector<stack<int>> arr(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
        pos[i] = i,arr[i].push(i);
    string ca, cb;
    int a, b;
    while(cin >> ca)
    {
        if(ca == "quit")
            break;
        cin >> a >> cb >> b;
        if(!valid(a, b, pos))
            continue;
        ca = ca + cb;
        if(ca == "moveonto")
            move_onto(a, b, arr, pos);
        else if(ca == "moveover")
            move_over(a, b, arr, pos);
        else if(ca == "pileonto")
            pile_onto(a, b, arr, pos);
        else if(ca == "pileover")
            pile_over(a, b, arr, pos);

    }
    for(int i = 0; i < n; i++)
    {
        cout << i << ":";
        stack<int> temp;
        while(!arr[i].empty())
            temp.push(arr[i].top()), arr[i].pop();
        while(!temp.empty())
            cout << " " << temp.top(), temp.pop();
        nl;
    }
}

int main()
{
    FASTIO;
    int t;
    t = 1;
    // cin >> t;
    while(t--)
    {
        cp();
    }
    return 0;
}