//Dream your Code, Code your Dream [Siriuslight -Subham Pal]
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;    typedef long long ll;    typedef long double ld;

const int inf = 1e9;
const ll INF = 1e18, MOD = 1e9+7;;

const int N = 1e5+5;
int n;
set <int> g[N];
int par[N], cnt, subtree[N];
bool vis[N];
char ans[N];

void dfs(int node, int parent){
    cnt++;
    subtree[node] = 1;
    for(auto v : g[node]){
        if(v != parent){
            dfs(v, node);
            subtree[node] += subtree[v];
        }
    }
}

int centroid(int node, int parent){
    for(auto v : g[node]){
        if(v != parent){
            if(subtree[v] > cnt){
                return centroid(v, node);
            }
        }
    }
    return node;
}

void decompose(int v, int parent){
    cnt = 0;
    dfs(v, parent);
    cnt >>= 1;
    int center = centroid(v, parent);
    par[center] = parent;
    ans[center] = ch;
    for(auto x : g[center]){
        g[x].erase(center);
        decompose(x, center);
    }
    g[center].clear();
}


int main(){
    FIO;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }

    decompose(1, 0);
    return 0;
}

