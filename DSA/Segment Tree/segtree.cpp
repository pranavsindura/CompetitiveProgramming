/*
Segment Tree, w/o Lazy updates

It is a data structure for Monoid
1. Associativity
2. Existence of Identity Element

How to use:
1. Set identity Element
2. Fill combine() function
3. Update the return, operations, updates of functions accordingly
*/

using ftype = int;

ftype t[4 * MAXN];
ftype e = 0; // Identity Element

ftype combine(ftype L, ftype R)
{

}

void build(int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = e;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void build(int v, int tl, int tr, vector<ftype> &arr)
{
    if(tl == tr)
        t[v] = arr[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, arr);
        build(v << 1 | 1, tm + 1, tr, arr);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void updatept(int v, int tl, int tr, int pos, ftype val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            updatept(v << 1, tl, tm, pos, val);
        else
            updatept(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void setpt(int v, int tl, int tr, int pos, ftype val)
{
    if(tl == tr)
        t[v] = val;
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            setpt(v << 1, tl, tm, pos, val);
        else
            setpt(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

ftype querypt(int v, int tl, int tr, int pos)
{
    if(tl == tr)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm)
            return querypt(v << 1, tl, tm, pos);
        else
            return querypt(v << 1 | 1, tm + 1, tr, pos);
    }
}

ftype query(int v, int tl, int tr, int l, int r)
{
    if(l > r) return e;

    if(tl == l && tr == r)
        return t[v];
    else
    {
        int tm = (tl + tr) >> 1;
        ftype L = query(v << 1, tl, tm, l, min(r, tm));
        ftype R = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(L, R);
    }
}

int kth_one(int v, int tl, int tr, int k) // Index of kth one
{
    if(k > t[v])
        return -1; // Does not exist
    if(tl == tr)
        return tl;
    else
    {
        int tm = (tl + tr) >> 1;
        if(t[v << 1] >= k)
            return kth_one(v << 1, tl, tm, k);
        else
            return kth_one(v << 1 | 1, tm + 1, tr, k - t[v << 1]);
    }
}

// Replacement of BS + range query
int first_above(int v, int tl, int tr, int k) // Index of first element >= k
{
    if(k > t[v])
        return -1; // Does not exist
    if(tl == tr)
        return tl;
    else
    {
        int tm = (tl + tr) >> 1;
        if(t[v << 1] >= k)
            return first_above(v << 1, tl, tm, k);
        else
            return first_above(v << 1 | 1, tm + 1, tr, k);
    }
}

int first_above(int v, int tl, int tr, int k, int l) // Index (>=l) of first element >= k
{
    if(tr < l) // Out of bounds
        return -1;
    if(k > t[v])
        return -1; // Does not exist
    if(tl == tr)
        return tl;
    else
    {
        int tm = (tl + tr) >> 1;
        if(t[v << 1] >= k)
        {
            int L = first_above(v << 1, tl, tm, k, l);
            if(L != -1) return L;
        }
        return first_above(v << 1 | 1, tm + 1, tr, k, l);
    }
}