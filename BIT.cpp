void update(int id, int val){
    while(id <= n){
        BIT[id] += val;
        id += (id & -id);
    }
}

int query(int id){
    int res = 0;
    while(id >= 1){
        res += BIT[id];
        id -= (id & -id);
    }
    return res;
}
