#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
const LL MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
 
struct DSU{
    vector<int> pa;
    DSU(int s): pa(s){
        iota(all(pa), 0);
    }
 
    int found(int x) {return (pa[x]==x)?x:found(pa[x]);}
 
    void unite(int x,int y){
        int p=found(x);
        int q=found(y);
        if (p==q) return;
        if (p<q){
            pa[q]=p;
        }
        else{
            pa[p]=q;
        }
    }
};
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for (auto& x:grid) cin>>x;
    DSU dsu(n*m);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (grid[i][j]=='.'){
                if (i-1>=0 && grid[i-1][j]=='.'){
                    dsu.unite(i*m+j, (i-1)*m+j);
                }
                if (j-1>=0 && grid[i][j-1]=='.'){
                    dsu.unite(i*m+j, i*m+j-1);
                }
            }
        }
    }
    set<int> res;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (grid[i][j]=='.'){
                res.insert(dsu.found(i*m+j));
            }
        }
    }
    cout<<res.size();
 
    return 0;
}
 
