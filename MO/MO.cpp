#include<bits/stdc++.h>
using namespace std;

 struct query{
    int l, r, id, no;
};

const int N = 200005;
int n, m, a[N], BLOCK;
struct query q[N];
int ans[N];

bool cmp(struct query a, struct query b){
    if(a.l/BLOCK != b.l/BLOCK)
        return a.l < b.l;
    return a.r < b.r;
}

void add(int pos){

}
void del(int pos){

}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> q[i].l >> q[i].r >> q[i].no;
        q[i].id = i;
    }
    BLOCK = (int)sqrt(n);
    sort(q, q + m, cmp);

    //Initialise CL and CR
    int CL = 1, CR = 1;
    
    for(int i = 0; i < m; i++){
        int L = q[i].l;
        int R = q[i].r;
        int key = q[i].no;

        while(L < CL){
            CL--;
            add(CL);
        }
        while(R > CR){
            CR++;
            add(CR);
        }
        while(L > CL){
            del(CL);
            CL++;
        }
        while(R < CR){
            del(CR);
            CR--;
        }
    }

    for(int i = 0; i < m; i++){
        cout << ans[i] <<'\n';
    }

}

