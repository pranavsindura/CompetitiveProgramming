#include<bits/stdc++.h>
using namespace std;
int tree[4000005];
int open[4000005];
int close[4000005];
void build(string s, int tl, int tr, int v)
{
    if(tl == tr)
    {
        tree[v] = 0;
        if(s[tl] == '(')
            open[v] = 1;
        else
            close[v] = 1;
    }
    else
    {
        int tm = (tr+tl)/2;
        build(s, tl, tm, v*2);
        build(s, tm+1, tr, v*2+1);
        tree[v] = tree[v*2]+tree[v*2+1];
    }
}

int main()
{
    string s;
    cin>>s;
    s = " " + s;

    int q;
    cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;
    }
    return 0;
}