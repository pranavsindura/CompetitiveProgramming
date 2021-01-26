/*
	Find Median in a Stream of integers
	Median at every insertion
*/

/*
	Approach 1 - PBDS, very high constant
	Approach 2 - Priority Queues
		Break stream into 2 PQs at the Median

		Maintain 2 PQs, one for all numbers on left of Median (Max Heap)
						one for all numbers on right of Median (Min Heap)
		Difference in lengths at any time will be <= 1

		If Left has more elements:
			If x is less than median:
				Move top element from left to right
				Put new element in Left
			else:
				Put new element in right
			Find new median
		else if Right has more elements:
			If x is less than median:
				Put new element in Left
			else:
				Move top element from right to left
				Put new element in right
			Find new median
		else:
			If x is less than median:
				Put new element in Left
			else:
				Put new element in right
			Find new median
*/
void cp()
{
    int n;
    cin >> n;
    priority_queue<int> pq_left;
    priority_queue<int, vector<int>, greater<int>> pq_right;
    int median = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(sz(pq_left) > sz(pq_right))
        {
            if(x < median)
            {
                // put in left
                // and move top element from left to right as it will be pushed because of new median
                int left = pq_left.top();
                pq_left.pop();
                pq_right.push(left);
                pq_left.push(x);
                median = pq_left.top() + pq_right.top();
                median = median / 2;
            }
            else
            {
                // put in right
                pq_right.push(x);
                median = pq_left.top() + pq_right.top();
                median = median / 2;
            }
        }
        else if(sz(pq_left) < sz(pq_right))
        {
            if(x < median)
            {
                // put in left
                pq_left.push(x);
                median = pq_left.top() + pq_right.top();
                median = median / 2;
            }
            else
            {
                // put in right
                // and move top element from right to left as it will be pushed because of new median
                int right = pq_right.top();
                pq_right.pop();
                pq_left.push(right);
                pq_right.push(x);
                median = pq_left.top() + pq_right.top();
                median = median / 2;
            }
        }
        else
        {
            if(x < median)
            {
                // put in left
                pq_left.push(x);
                median = pq_left.top();
            }
            else
            {
                // put in right
                pq_right.push(x);
                median = pq_right.top();
            }
        }
        cout << median << endl;
    }
}