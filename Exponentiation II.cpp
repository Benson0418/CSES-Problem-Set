#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto tpot=[](ll a, ll n, ll P) -> ll{
        ll res = 1L;
        a%=P;
        while (n){
            if (n&1) res=res*a%P;
            a=a*a%P;
            n>>=1;
        }
        return res;
    };

    int n;
    cin>>n;
    while (n--){
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<tpot(a,tpot(b,c,MOD-1),MOD)<<"\n";
    }

    return 0;
}
