
const int N = (int)2e5 + 5;

template <class Type>
class SegTree{
    Type T[N * 4], lazy[N * 4];
    Type defaultValue = 0;

    Type SegFunc(Type x, Type y){
        return x + y;
    }
    public :
    void update(int node, int treeLeft, int treeRight, int index, Type value){
        if(treeLeft == treeRight){
            T[node] = value;
        }
        else{
            int mid = (treeLeft + treeRight) >> 1;
            if(treeLeft <= index && index <= mid)
                update(node << 1, treeLeft, mid, index, value);
            else
                update(node << 1 ^ 1, mid + 1, treeRight, index, value);
            T[node] = SegFunc(T[node << 1], T[node << 1 ^ 1]);
        }
    }

    Type query(int node, int treeLeft, int treeRight, int queryLeft, int queryRight){
        if(queryRight < treeLeft || queryLeft > treeRight)
            return defaultValue;
        lazyupdate(node, treeLeft, treeRight);

        if(queryLeft <= treeLeft && treeRight <= queryRight)
            return T[node];

        int mid = (treeLeft + treeRight) >> 1;
        Type leftResult = query(node << 1, treeLeft, mid, queryLeft, queryRight);
        Type rightResult = query(node << 1 ^ 1, mid + 1, treeRight, queryLeft, queryRight);
        return SegFunc(leftResult, rightResult);
    }

    void lazyupdate(int node, int treeLeft, int treeRight){
        if(!lazy[node])
            return;
        T[node] += lazy[node] * (treeRight - treeLeft + 1);
        if(treeLeft != treeRight){
            lazy[node << 1] += lazy[node];
            lazy[node << 1 ^ 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    void rangeUpdate(int node, int treeLeft, int treeRight, int queryLeft, int queryRight, Type value){
        lazyupdate(node, treeLeft, treeRight);

        if(queryRight < treeLeft || queryLeft > treeRight)
            return;

        if(queryLeft <= treeLeft && treeRight <= queryRight){
            lazy[node] += value;
            lazyupdate(node, treeLeft, treeRight);
        }
        else{
            int mid = (treeLeft + treeRight) >> 1;
            rangeUpdate(node << 1, treeLeft, mid, queryLeft, queryRight, value);
            rangeUpdate(node << 1 ^ 1, mid + 1, treeRight, queryLeft, queryRight, value);
            T[node] = SegFunc(T[node << 1], T[node << 1 ^ 1]);
        }
    }
};

SegTree <long long> ST;
