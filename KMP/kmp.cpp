#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6+5;
string pat, txt;
int lps[N];
vector<int> ans;

void prekmp(){
    int i = 0, j = -1;
    lps[i] = j;
    while(i < pat.length()){
        while(j >= 0 && pat[i] != pat[j]) j = lps[j];
        i++; j++;
        lps[i] = j;
    }
}

vector<int> kmp(){
    int i = 0, j = 0;
    vector<int> res;
    while(i < txt.size()){
        while(j >= 0 && txt[i] != pat[j]) j = lps[j];
        i++, j++;
        if(j == pat.size()){
            res.push_back(i - j);
            j = lps[j];
        }
    }
    return res;
}

int main(){
    cin >> txt >> pat;
    prekmp();
    ans = kmp();
    for(auto x : ans){
        cout << x <<" ";
    }
}

