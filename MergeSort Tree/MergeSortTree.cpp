const ll N = 2e5+5;
vector<ll> T[4*N], pre[4*N];


void build(ll v, ll tl, ll tr){
    if(tl == tr){
        T[v].push_back(a[tl]);
    }
    else{
        ll tm = (tl + tr) >> 1;
        build(v<<1,tl,tm);
        build(v<<1^1, tm + 1, tr);
        merge(T[v<<1].begin(), T[v<<1].end(), T[v<<1^1].begin(), T[v<<1^1].end(), back_inserter(T[v]));
    }
}

