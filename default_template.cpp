//Dream your Code, Code your Dream [Siriuslight -Subham Pal]
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;    typedef long long ll;    typedef long double ld;

const int inf = 1e9;
const ll INF = 1e18, MOD = 1e9+7;;

ll pow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b = b >> 1;
	}
	return res;
}

ll gcd(ll a, ll b){
	if(!b)	return a;
	return gcd(b, a % b);
}

int main(){
    FIO;
    
    return 0;
}