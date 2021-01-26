/*
	Snake and Ladder

	Given a Board of 5x6
	And list of Jumps (ladders/snakes) find minimum die throws to get from start -> 1 to end -> 30
*/

/*
	Approach 1 - Simple BFS problem

	Since All Die throws cost 1,
	We dont need to use dijkstra can be done with BFS

	Notice that if jump is available we have to take it, mandatory
*/

// Approach 1
void cp()
{
    int n;
    cin >> n;
    vector<int> jump(31, -1);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        //jump from a to b
        jump[a] = b;
    }
    vector<bool> vis(31, false);
    queue<pi> q;
    //pos, throws
    q.push({1, 0});
    int ans = 0;
    while(!q.empty())
    {
        int pos = q.front().ff;
        int throws = q.front().ss;
        q.pop();
        vis[pos] = true;

        //also see if you can directly jump from here, have to take it
        if(~jump[pos])
        {
            pos = jump[pos];
        }
        vis[pos] = true;
        // check if won
        if(pos == 30)
        {
            ans = throws;
            break;
        }

        // throw a die
        for(int i = 1; i <= 6; i++)
        {
            int npos = pos + i;
            if(npos >= 1 && npos <= 30 && !vis[npos])
                q.push({npos, throws + 1}), vis[npos] = true;
        }
    }

    cout << ans << endl;
}
