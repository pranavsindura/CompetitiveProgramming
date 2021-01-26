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
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
using namespace std;

int main()
{
    FASTIO;
    string s;
    cin>>s;
    bool f = false;
    for(int i=0;i<ln(s);i++)
    {
        int ques=0;
        int hash[26]={0};
        for(int j=0;j<26 && i+j < ln(s);j++)
        {
            if(s[i+j] =='?')
                ques++;
            else
                hash[s[i+j]-'A']++;
        }
        int miss=0;
        vector<int> missarr;
        for(int i=0;i<26;i++){
            if(!hash[i]){
                miss++;
                missarr.push_back(i);
            }
        }
        if(ques<miss)
            continue;
        int x=0;
        for(int j=0;j<26 && i+j<ln(s);j++)
        {
            if(s[i+j]=='?')
            {
                s[i+j] = char(missarr[x]+65);
                x=(x+1)%sz(missarr);
            }
        }
        f=true;
    }
    for(int i=0;i<ln(s);i++)
        if(s[i]=='?')
            s[i]='P';
    if(f)
        cout<<s;
    else
        cout<<-1;
    return 0;
}