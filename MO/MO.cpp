
struct query{
    int l, r, id, no;
};

const int N = 200005;
int n, m, a[N], BLOCK;
struct query q[N];
int ans[N];

inline bool cmp(const struct query &a, const struct query &b){
	int num = a.l / block;
	if (num != b.l / block)
		return a.l < b.l;
	if (num&1)
		return a.r < b.r;
	return a.r > b.r;
}

inline void add(int pos){

}

inline void del(int pos){

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
