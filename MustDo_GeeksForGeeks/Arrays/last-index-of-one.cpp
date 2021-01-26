/*
    FIND LAST INDEX OF 1 IN BINARY STRING
*/

void cp()
{
    string s;
    cin>>s;
    int last_ind = -1;
    for(int i=0;i<ln(s);i++)
        if(s[i] == '1')
            last_ind = i;
    cout<<last_ind<<endl;
        
}
