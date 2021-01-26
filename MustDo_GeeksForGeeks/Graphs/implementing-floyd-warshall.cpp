/*
	Floyd Warshall

	Multiple Source Multiple Destination Shortest Path
	Does not work with negative cycles

*/
/*
	For every node k:
		For every node i:
			For every node j:

				relax path of i to j via k
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
*/

void cp()
{
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][k] == MAXN || arr[k][j] == MAXN)
                    continue;
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == MAXN)
                cout << "INF ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}