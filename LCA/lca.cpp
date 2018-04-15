#include<bits/stdc++.h>
using namespace std;

const int N=100005, LG = 19;
int n, up[N][20],l, dep[N],q,sum[N], a[N],b[N];
vector<int> g[N];

void dfs(int x, int p)
{
    up[x][0] = p;
    dep[x] = dep[p] + 1;
    for(auto child : g[x])
    {
        if(child != p)
            {
                dfs(child, x);
                sum[x] += sum[child];
            }
    }
}


int lca(int x, int y)
{
    if(dep[x] < dep[y])
        swap(x,y);
    int dif = dep[x] - dep[y];
    for(int i = 0; i <= LG; i++){
        if(dif & (1<<i)){
            x = up[x][i];
        }
    }
    if(x != y){
        for(int i = LG; i >= 0; i--){
            if(up[x][i] != up[y][i]){
                x = up[x][i];
                y = up[y][i];
            }
        }
       x = up[x][0];
    }
    return x;
}

int look(int v, int d)
{

    for(int i = 20; i >= 0; i--)
    {
        if((d>>i)&1)
            v = up[v][i];
    }
    return v;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        a[i] = x;
        b[i] = y;
    }

    dfs(1,0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= LG; j++){
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        sum[x]++;
        sum[y]++;
        sum[lca(x,y)] -=2;
    }
    dfs(1,0);
    for(int i = 0; i < n - 1; i++)
    {
        if(dep[a[i]] < dep[b[i]])
            swap(a[i],b[i]);
        cout << sum[a[i]] <<" ";
    }


}

