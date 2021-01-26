/*
	ANAGRAM
	Check if two strings are anagram of each other.
*/
/*
	Approach 1 - Sort and check if equal O(nlogn)
	Approach 2 - Use hashing and compare frequencies O(n)
*/
// Approach 1
void cp()
{
    string a, b;
    cin >> a >> b;
    sort(all(a));
    sort(all(b));
    bool ok = a == b;
    cout << (ok ? "YES\n" : "NO\n");
}
//Approach 2
void cp()
{
    string a, b;
    cin >> a >> b;
    vector<int> hash_a(26, 0), hash_b(26, 0);
    for(char x : a)
        hash_a[x - 'a']++;
    for(char x : b)
        hash_b[x - 'a']++;
    bool ok = hash_a == hash_b;
    cout << (ok ? "YES\n" : "NO\n");
}