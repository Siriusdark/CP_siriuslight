#include<bits/stdc++.h>
using namespace std;

const int NX = 1e5+5, MX = 26;
struct trie{
    int tr[NX][MX], sz = 1, cnt[NX][MX];
    int fin[NX][MX];

    void insert(string s){
        int v = 0, bit;
        for(auto c : s){
            bit = c - 'a';
            if(!tr[v][bit]){
                tr[v][bit] = sz++;
            }
            cnt[v][bit]++;
            v = tr[v][bit];
        }
        fin[v][bit]++;
    }

    bool search(string s){
        int v = 0, bit;
        for(auto c : s){
            bit = c - 'a';
            if(cnt[v][bit] <= 0){
                return 0;
            }
            v = tr[v][bit];
        }
        return fin[v][bit] > 0;
    }

    void erase(string s){
        int v = 0, bit;
        for(auto c : s){
            bit = c - 'a';
            cnt[v][bit]--;
            v = tr[v][bit];
        }
        fin[v][bit]--;
    }

} T;

