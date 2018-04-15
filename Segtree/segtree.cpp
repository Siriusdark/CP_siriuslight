#include <bits/stdc++.h>
using namespace std;

const int N = 2000007;
long long T[4*N], lazy[4*N];

void build(int v, int tl, int tr)
{
    if(tl == tr)
    {
        T[v] += state[tl];
    }
    else
    {
        int tm = tl + tr >> 1;
        build(v<<1, tl, tm);
        build(v<<1^1, tm + 1, tr);
        T[v] = T[v<<1] + T[v<<1^1];
    }
}

void lazyupdate(int v, int tl, int tr)
{
    if(!lazy[v])
        return;
    T[v] = (tr - tl + 1) - T[v];
    if(tl != tr)
    {
        lazy[v<<1] = !lazy[v<<1];
        lazy[v<<1^1] = !lazy[v<<1^1];
    }
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r)
{
    lazyupdate(v, tl, tr);
    if(l > r || tl > r || tr < l)
        return;
    if(tl >= l && tr <= r)
    {
        lazy[v] = 1;
        lazyupdate(v, tl, tr);
    }
    else
    {
        int tm = tl + tr >> 1;
        update(v<<1, tl, tm, l, r);
        update(v<<1^1, tm + 1, tr, l, r);
        T[v] = T[v<<1] + T[v<<1^1];
    }

}

int query(int v, int tl, int tr, int l, int r)
{   lazyupdate(v, tl, tr);
   if(l > r || tl > r || tr < l)
        return 0;
    if(tl >= l && tr <= r)
        return T[v];
    int tm = tl + tr >> 1;
    return (query(v<<1, tl, tm, l, r) + query(v<<1^1, tm + 1, tr, l, r));

}

int main()
{
    
    build(1, 0, n-1);
    
    query(1, 0, n*2-1, pos[v].first, pos[v].second) / 2 <<'\n';
    update(1, 0, n*2-1, pos[v].first, pos[v].second);

    

}
