/*
	Josephus Problem
	Given n people standing in a circle and number k
	k-1 people are skipped kth person is killed
	find the position of the last alive person
*/
/*
	Approach 1 - Brute Force
*/

int josephus(int n, int k)
{
    vector<bool> alive(n, true);
    int rem = n;
    int pos = 0;
    while(rem > 1)
    {
        //find kth alive person
        int found = 0;
        while(found < k)
        {
            if(alive[pos])
                found++;
            if(found == k)
                break;
            pos = (pos + 1) % n;
        }
        // kill him
        alive[pos] = false;
        rem--;
    }
    for(int i = 0; i < n; i++)
        if(alive[i])
            return i + 1;
}
