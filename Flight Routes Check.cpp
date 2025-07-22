#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define F first
#define S second
using LL=long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> G(n+1), rG(n+1);
    for (int a,b,i=1;i<=m;++i){
        cin>>a>>b;
        G[a].pb(b);
        rG[b].pb(a);
    }
    vector<int> topo;
    vector<int> visited(n+1);
    function<void(int)> dfs=[&](int i){
        if (visited[i]) return;

        visited[i]=1;
        for (auto& x:G[i]){
            if (!visited[x]){
                dfs(x);
            }
        }
        topo.pb(i); //處理完最後才壓入topo

        return;
    };
    for(int i=1;i<=n;++i){
        dfs(i);
    }
    vector<int> res;
    function<void(int)> dfs2=[&](int x){
        visited[x]=0;
        for (auto& y:rG[x]){
            if (!visited[y]) continue;
            dfs2(y);
        }
        return;
    };
    reverse(all(topo));
    for (auto& x:topo){
        if (visited[x]){
            res.pb(x);
            dfs2(x);
        }
    }
    for (auto& x:topo){
        cerr<<x<<" ";
    }
    cerr<<endl;

    if (sz(res)==1){
        cout<<"YES";
    }
    else{
        cout<<"NO\n";
        cout<<res[1]<<" "<<res[0];
    }

    return 0;
}




