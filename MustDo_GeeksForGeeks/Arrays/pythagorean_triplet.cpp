/*
    Check if pythagorean triplet exists in array

    Approach 1 - Brute Force O(n^2)
    Frequency is small brute force.
*/

int freq[1005];
void cp()
{
    clr(freq, 0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        freq[x]++;
    }
    bool ok = false;
    for(int i=1;i<=1000;i++)
    {
        if(!freq[i])
            continue;
        for(int j=i+1;j<=1000;j++)
        {
            if(!freq[j])
                continue;
            int c2 = i*i + j*j;
            if((int)sqrt(c2) * (int)sqrt(c2) == c2)
            {
                if(freq[(int)sqrt(c2)]){
                    // cout<<i<<" "<<j<<" "<<(int)sqrt(c2)<<endl;
                    ok = true;
                }
            }
        }
    }
    cout<<(ok?"Yes\n":"No\n");
}