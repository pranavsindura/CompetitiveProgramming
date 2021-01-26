/*
	Implement LRU CACHE with given capacity
*/

// List Implementation
// Allows Deletion and insertion anywhere once position is known
// Everytime an item is accessed we delete it from list and move it to the front
// this means that LRU item is always at the last of the list!
class LRUCache
{
private:
    int capacity;
    int count;
    vector<list<pair<int, int>>::iterator> pos;
    vector<bool> used;
    // Value, Key pair
    list<pair<int, int>> dq;
public:
    LRUCache(int cap)
    {
        // constructor for cache
        count = 0;
        capacity = cap;
        used = vector<bool>(1005);
        pos = vector<list<pair<int, int>>::iterator>(1005);
    }

    int get(int key)
    {
        int val = -1;
        if(used[key])
        {
            pair<int, int> key_val = *pos[key];
            val = key_val.second;
            dq.erase(pos[key]);
            dq.push_front(key_val);
            pos[key] = dq.begin();
        }
        return val;
    }

    void set(int key, int value)
    {
        if(used[key])
        {
            dq.erase(pos[key]);
            dq.push_front({key, value});
            pos[key] = dq.begin();
        }
        else
        {
            if(count < capacity)
            {
                count++;
                dq.push_front({key, value});
                pos[key] = dq.begin();
            }
            else
            {
                pair<int, int> lru = *dq.rbegin();
                dq.pop_back();
                used[lru.first] = 0;

                dq.push_front({key, value});
                pos[key] = dq.begin();
            }
            used[key] = 1;
        }
    }
};


/*
	We can hold how many times a key was called during the whole queries to find the last occurance of it.
	To remove element from deque, we iterate till we reach last occurance of some key, that is LRU, delete it
	Rest functions are standard
*/

// Deque Implementation
// https://www.youtube.com/watch?v=FN8U19xxGog&t=1097s

class LRUCache
{
private:
    int capacity;
    int count;
    vector<bool> used;
    vector<int> cache;
    vector<int> cnt;
    deque<int> dq;
public:
    LRUCache(int cap)
    {
        // constructor for cache
        count = 0;
        capacity = cap;
        cache = vector<int>(1005);
        cnt = vector<int>(1005);
        used = vector<bool>(1005);
    }

    int get(int key)
    {
        int val = -1;
        if(used[key])
        {
            val = cache[key];
            cnt[key]++;
            dq.push_back(key);
        }
        return val;
    }

    void set(int key, int value)
    {
        if(used[key])
        {
            cache[key] = value;
            cnt[key]++;
            dq.push_back(key);
        }
        else
        {
            if(count < capacity)
            {
                count++;
                used[key] = 1;
                cache[key] = value;
                cnt[key]++;
                dq.push_back(key);
            }
            else
            {
                while(true)
                {
                    int lru = dq.front();
                    dq.pop_front();
                    cnt[lru]--;
                    if(cnt[lru] == 0)
                    {
                        used[lru] = 0;
                        break;
                    }
                }
                used[key] = 1;
                cache[key] = value;
                cnt[key]++;
                dq.push_back(key);
            }
        }
    }
};