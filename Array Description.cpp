#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
const LL MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n,m;
    cin>>n>>m;
    vector<LL> X(n);
    for (auto& x:X) cin>>x;
    vector<LL> dpp(m+1),dpc(m+1);
    for (LL i=0;i<n;++i){
        if (i==0){
            if (X[0]==0){
                for (int j=1;j<=m;++j) dpc[j]=1;
            }
            else{
                dpc[X[i]] = 1;
            }
        }
        else{
            if (X[i]==0){
                for (LL j=1;j<=m;++j){
                    dpc[j]=dpp[j];
                    if (j-1>0) {
                        dpc[j]+=dpp[j-1];
                        dpc[j]%=MOD;
                    }
                    if (j+1<=m) {
                        dpc[j]+=dpp[j+1];
                        dpc[j]%=MOD;
                    }
                }
            }
            else{
                dpc[X[i]]=dpp[X[i]];
                if (X[i]-1>0) {
                    dpc[X[i]]+=dpp[X[i]-1];
                    dpc[X[i]]%=MOD;
                }
                if (X[i]+1<=m) {
                    dpc[X[i]]+=dpp[X[i]+1];
                    dpc[X[i]]%=MOD;
                }
            }
        }
        swap(dpp,dpc);
        fill(all(dpc), 0LL);
    }
    cout<<accumulate(all(dpp), 0LL)%MOD;





    return 0;
}
