/*
	IMPLEMENT STRSTR
	Find index of first occurance of String X in String S
*/

/*
	Approach 1 - Brute Force Find O(n^2)
	Approach 2 - KMP String Matching O(n)
*/

//Approach 1
/* The function should return position where the target string
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
    int n = s.length();
    int m = x.length();
    for(int i = 0; i < n - m + 1; i++)
    {
        bool ok = true;
        for(int j = 0; j < m; j++)
        {
            if(s[i + j] != x[j])
            {
                ok = false;
                break;
            }
        }
        if(ok)
            return i;
    }
    return -1;
}

//Approach 2
void createLPS(string s, int lps[])
{
    int i = 1, m = 0, n = s.length();
    lps[0] = 0;
    while(i < n)
    {
        if(s[i] == s[m])
        {
            lps[i] = m + 1;
            i++;
            m++;
        }
        else if(s[i] != s[m] && m != 0)
        {
            m = lps[m - 1];
        }
        else
        {
            lps[i] = 0, i++;
        }
    }
}

int strstr(string s, string x)
{
    int n = s.length(), m = x.length();
    int lps[n + 1];
    createLPS(x, lps);
    int i = 0, j = 0;
    while(i < n)
    {
        if(s[i] != x[j])
        {
            if(j == 0)
                i++;
            else
                j = lps[j - 1];
        }
        else
        {
            i++, j++;
            if(j == m)
            {
                return i - m;
            }
        }
    }
    return -1;
}