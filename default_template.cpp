//Dream your Code, Code your Dream [Siriuslight -Subham Pal]
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;    typedef long long ll;    typedef long double ld;
const int inf = 1e9, N = 1e6+5;
const ll INF = 1e18, MOD = 1e9+7;;
ll power(ll a,ll b,ll m=MOD){ll r=1;while(b>0){if(b&1)r=r*a%m;a=a*a%m;b>>=1;}return r;}
ll gcd(ll a, ll b){if(b>a)swap(a,b);if(!b)return a;return gcd(b, a % b);}

int main(){
    FIO;
    cout << setprecision(10) << fixed;

    return 0;
}
