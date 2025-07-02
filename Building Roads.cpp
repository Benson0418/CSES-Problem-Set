#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
const LL MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct DSU{
    vector<int> pa;
    DSU(int n): pa(n){iota(all(pa), 0);}

    int found(int x) {return (pa[x]==x?x:found(pa[x]));}

    void unite(int x,int y){
        int p=found(x);
        int q=found(y);
        if (p==q) return;
        else if (p<q){
            pa[q]=p;
        }
        else {
            pa[p]=q;
        }
    }

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a=0,b=0;
    cin>>n>>m;
    DSU dsu(n+1);
    for (int i=0;i<m;++i){
        cin>>a>>b;
        dsu.unite(a,b);
    }
    int res=0;
    vector<pair<int,int>> bridge;
    for (int i=1;i<=n;++i){
        if (dsu.found(i)!=1){
            dsu.unite(1,i);
            ++res;
            bridge.push_back({1,i});
        }
    }
    cout<<res<<"\n";
    for (auto& x:bridge){
        cout<<x.fi<<" "<<x.se<<"\n";
    }
    return 0;
}

