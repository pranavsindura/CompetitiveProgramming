#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define eps 0.000000001
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define sz(x) ((int)x.size())
#define ln(x) ((int)x.length())
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl
#define clr(x,v) memset(x, v, sizeof(x))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;

// MAX HEAP
class MaxHeap
{
    int heap_size;
    vector<int> heap;
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }

    void heapify(int i)
    {
        int largest = i;
        int l = left(i);
        int r = right(i);
        if(l < heap_size && heap[l] > heap[largest])
            largest = l;
        if(r < heap_size && heap[r] > heap[largest])
            largest = r;
        if(largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
public:
    MaxHeap()
    {
        heap_size = 0;
    }
    void push(int k)
    {
        heap.push_back(k);
        heap_size++;
        int i = heap_size - 1;
        while(i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int top()
    {
        if(heap_size)
            return heap[0];
        else
            return -1;
    }

    void pop()
    {
        if(heap_size == 0)
            return;
        heap[0] = heap[heap_size - 1];
        heap_size--;
        heap.pop_back();
        heapify(0);
    }

    void increase_val(int i, int new_val)
    {
        // assuming new val is greater
        heap[i] = new_val;
        while(i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void delete_pos(int i)
    {
        // Deletes node i not position i in array
        // will depend on heap structure
        if(i >= heap_size)
            return;
        increase_val(i, INT_MAX);
        pop();
    }

    void display()
    {
        cout << "HEAP(" << heap_size << "): ";
        vector<int> temp;
        while(heap_size)
        {
            temp.push_back(top());
            pop();
        }
        for(int x : temp)
            cout << x << " ";
        cout << endl;
        while(!temp.empty())
        {
            push(temp.back());
            temp.pop_back();
        }
    }

};
int main()
{
    MaxHeap heap;
    //1 x - Insert X
    //2   - View Top
    //3   - Pop
    //4 x - Delete node x
    while(true)
    {
        int q;
        cin >> q;
        if(q == 1)
        {
            int x;
            cin >> x;
            heap.push(x);
        }
        else if(q == 2)
        {
            cout << heap.top() << endl;
        }
        else if(q == 3)
        {
            heap.pop();
        }
        else if(q == 4)
        {
            int x;
            cin >> x;
            heap.delete_pos(x);
        }
        heap.display();
    }
    return 0;
}