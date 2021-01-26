/*
	Huffman Decoding

	Given encoded string and Huffman MinHeap, decode the string

	Huffman Encoding
	(https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/)

	Huffman Decoding
	(https://www.geeksforgeeks.org/huffman-decoding/)
*/

/*Complete the function below
Which contains 2 arguments
1) root of the tree formed while encoding
2) Encoded String*/

void rec(MinHeapNode *root, string &s, map<string, char> &key)
{
    if(root == NULL)
        return;
    if(root->left)
    {
        s += '0';
        rec(root->left, s, key);
        s.pop_back();
    }
    if(root->right)
    {
        s += '1';
        rec(root->right, s, key);
        s.pop_back();
    }

    if(root->left == NULL && root->right == NULL)
    {
        key[s] = root->data;
    }
}

string decode_file(struct MinHeapNode *root, string s)
{
    map<string, char> key;
    string code;
    rec(root, code, key);
    string temp, ans;
    for(int i = 0; i < (int)s.length(); i++)
    {
        temp += s[i];
        if(key.find(temp) != end(key))
        {
            ans += key[temp];
            temp = "";
        }
    }
    return ans;
}