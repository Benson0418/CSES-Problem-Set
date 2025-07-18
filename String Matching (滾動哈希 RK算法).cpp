#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())

using LL = long long;
const int BASE = 131;
const int MOD = 1e9 + 9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text,patt;
    cin>>text>>patt;
    int n=sz(text),m=sz(patt);

    vector<LL> power(n+1,1),H(n+1);
    LL hp=0;

    for (int i=1;i<=n;++i){
        power[i]=(power[i-1]*BASE)%MOD;
    }

    for (int i=1;i<=n;++i){
        H[i]=(H[i-1]*BASE+text[i-1])%MOD;
    }
    for (int i=0;i<m;++i){
        hp=(hp*BASE+patt[i])%MOD;
    }

    int cnt=0;
    for (int i=0;i+m<=n;++i){
        LL sub_hash=(H[i+m]-H[i]*power[m]%MOD+MOD)%MOD;
        if (sub_hash==hp) ++cnt;
    }

    cout<<cnt;
    return 0;
}

