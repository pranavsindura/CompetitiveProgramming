/*
	Find Quadruple with given sum
*/
/*
	Approach 1 - Pick 4 O(n^4)

	Approach 2 - Hashing O(n^3 log n) or O(n^3)
		Seeing as elements lie in -100->+100 range, can try hashing
		Pick 3, see if last exists and make a quadruple

	Approach 3 - Hashing O(n^2 logn) or O(n^2)
		Pick 2 and make a hash of the different sums
		Loop on different sums and see if k-sum exists using your hash
		Store in hash different pairs that form those sums
		Pick 2 from those pairs
*/
bool check(tuple<int, int, int, int> &t, map<int, int> &freq)
{
    int a, b, c, d;
    tie(a, b, c, d) = t;
    bool ok = true;
    if(freq[a] > 0)
    {
        freq[a]--;
        if(freq[b] > 0)
        {
            freq[b]--;
            if(freq[c] > 0)
            {
                freq[c]--;
                if(freq[d] > 0)
                {
                    //ok
                }
                else
                    ok = false;
                freq[c]++;
            }
            else
                ok = false;
            freq[b]++;
        }
        else
            ok = false;
        freq[a]++;

    }
    else
        ok = false;
    return ok;
}

void cp()
{
    int n, k;
    cin >> n >> k;
    map<int, int> freq;
    vector<int> arr;
    // Single Element Frequency
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.pb(x);
        freq[x]++;
    }
    map<int, vector<pi>> sum_idx;
    set<tuple<int, int, int, int>> ans;

    // Pair of sums
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            sum_idx[arr[i] + arr[j]].pb({arr[i], arr[j]});
        }
    }
    for(auto &v : sum_idx)
    {
        int need = k - v.ff;
        if(sz(sum_idx[need]))
        {
            // Can be same
            if(need == v.ff)
            {
                for(int i = 0; i < sz(v.ss); i++)
                {
                    for(int j = i + 1; j < sz(v.ss); j++)
                    {
                        vector<int> res = {v.ss[i].ff, v.ss[i].ss, v.ss[j].ff, v.ss[j].ss};
                        sort(all(res));

                        tuple<int, int, int, int> t = make_tuple(res[0], res[1], res[2], res[3]);
                        
                        if(check(t, freq))
                            ans.insert(t);
                    }
                }
            }
            // Can be different
            else
            {
                for(int i = 0; i < sz(sum_idx[need]); i++)
                {
                    for(int j = 0; j < sz(v.ss); j++)
                    {
                        vector<int> res = {sum_idx[need][i].ff, sum_idx[need][i].ss, v.ss[j].ff, v.ss[j].ss};
                        sort(all(res));

                        tuple<int, int, int, int> t = make_tuple(res[0], res[1], res[2], res[3]);

                        if(check(t, freq))
                            ans.insert(t);
                    }
                }
            }
        }
    }
    if(!ans.empty())
    {
        for(tuple<int, int, int, int> t : ans)
        {
            int a, b, c, d;
            tie(a, b, c, d) = t;
            cout << a << " " << b << " " << c << " " << d << " $";
        }
    }
    else
        cout << -1;
    cout << endl;
}