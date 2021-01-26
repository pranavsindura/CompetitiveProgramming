/*
	Fist Petrol Pump at which I should start journey to complete a Circular Tour
	Given petrol filled and distance to next station
*/

/*
	Approach 1 - Start at every Pump and find first O(n^2)
	Approach 2 - Two Pointers O(n)
		l is the petrol pump i start with
		r is the petrol pump ive reached so far
		if at any time their distance becomes n is means that i've completed the tour
		If difference becomes -ve i can't go on, change i
		else change j
*/

// Approach 2
/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};
*/
int tour(petrolPump p[], int n)
{
    //Your code here
    vector<int> diff(n);
    for(int i = 0; i < n; i++)
        diff[i] = p[i].petrol - p[i].distance;
    int i = 0, j = 0;
    int sum = 0;
    while(i < n)
    {
        if(j - i == n)
            return i;
        sum += diff[j % n];
        if(sum < 0)
        {
            if(i < j)
                sum -= diff[i], i++;
            else
                i++, j = i, sum = 0;
        }
        else
        {
            j++;
        }
    }
    return -1;
}