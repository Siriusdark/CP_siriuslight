//Author : Siriuslight
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0),cout<<setprecision(10)<<fixed;
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll inf = 1e9+100, N = 2e5+5;
const ll INF = 1e18+100, MOD = 1e9+7;

ll powmod(ll a,ll b,ll m=MOD){ll r=1;while(b>0){if(b&1)r=r*a%m;a=a*a%m;b>>=1;}return r;}
ll power(ll a,ll b){ll r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll inv(ll a, ll m = MOD){return powmod(a,m-2,m);}
ll lcm(ll a,ll b){return(a*b)/gcd(a,b);}

//ordered_set X;
//X.insert(3);
//X.order_of_key(3) no of elements less than 3
//*X.find_by_order(n) nth greatest element(0-indexed)

int main(){
    FIO;
    

};
