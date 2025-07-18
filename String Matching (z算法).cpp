#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_tuple
#define eb emplace_back

using LL = long long;
const LL INF = 0x3f3f3f3f3f3f3f3fll;
#define g0(X) (get<0>(X))
#define g1(X) (get<1>(X))
#define g2(X) (get<2>(X))
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string patt,text;
    cin>>text>>patt;
    string s=patt+'$'+text;

    vector<int> z(sz(s));
    int l=0,r=0,cnt=0;

    for (int i=1;i<sz(s);++i){
        if (i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while (i+z[i]<sz(s) && s[z[i]]==s[i+z[i]]){
            ++z[i];
        }
        if (i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }

    for(int i=sz(patt)+1;i<sz(s);++i){
        if (z[i]==sz(patt)) ++cnt;
    }
    cout<<cnt;

    return 0;
}

