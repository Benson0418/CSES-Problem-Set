#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
const LL MOD = 1e9+7;
 
pair<int,vector<int>> cmp(pair<int,vector<int>> X, pair<int,vector<int>> Y){
    return (X.f>Y.f?X:Y);
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;
    vector<int> A(m+1),B(n+1);
    for(int i=1;i<=m;++i){
        cin>>A[i];
    }
    for(int i=1;i<=n;++i){
        cin>>B[i];
    }
    vector<pair<int,vector<int>>> dpp(n+1),dpc(n+1);
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j){
            if (A[i]==B[j]){
                pair<int,vector<int>> tmp;
                tmp.f = dpp[j-1].f+1;
                tmp.s = dpp[j-1].s;
                tmp.s.push_back(A[i]);
                pair<int,vector<int>> X = cmp(tmp,cmp(dpc[j-1],dpp[j]));
                dpc[j].f = X.f;
                dpc[j].s = X.s;
            }
            else{
                 pair<int,vector<int>> X = cmp(dpc[j-1],dpp[j]);
                dpc[j].f = X.f;
                dpc[j].s = X.s;
            }
        }
        swap(dpp,dpc);
    }
    cout<<dpp[n].f<<"\n";
    for (auto& x:dpp[n].s) cout<<x<<" ";
 
    return 0;
}
