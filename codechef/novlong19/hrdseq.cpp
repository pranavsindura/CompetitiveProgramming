#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int seq[130];
pair<bool, int> seqfind(int e, int pos)
{
    for (int i = pos; i >= 1; i--)
    {
        if (seq[i] == e)
            return {true, i};
    }
    return {false, 0};
}
int occur(int n)
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(seq[i] == seq[n])
            count++;
    }
    return count;
}
void init()
{
    seq[1] = 0;
    for (int i = 2; i < 130; i++)
    {
        pair<bool, int> a = seqfind(seq[i - 1], i - 2);
        if (a.first)
        {
            seq[i] = i - 1 - a.second;
        }
        else
        {
            seq[i] = 0;
        }
    }
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<occur(n)<<endl;
    }
    return 0;
}