#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
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
    vector<vector<int>> G(n+1);
    for (int a,b,i=1;i<=m;++i){
        cin>>a>>b;
        G[a].pb(b);
    }

    vector<int> dfs_num(n+1),dfs_low(n+1);
    vector<int> stk,inStack(n+1);
    vector<vector<int>> SCCs;
    int timer=0,SCC=0;

    function<void(int)> dfs=[&](int u){
        if (dfs_num[u]) return;
        dfs_num[u]=dfs_low[u]=++timer;
        stk.pb(u);
        inStack[u]=1;

        for (auto& v:G[u]){
            if (!dfs_num[v]){
                dfs(v);
                dfs_low[u]=min(dfs_low[u],dfs_low[v]);
            }
            else if(inStack[v]){
                dfs_low[u]=min(dfs_low[u],dfs_low[v]);
            }
        }

        if (dfs_low[u]==dfs_num[u]){
            ++SCC;
            SCCs.eb();
            int v;
            while (true){
                v=stk.back();
                stk.pop_back();
                inStack[v]=0;
                SCCs.back().pb(v);
                if (v==u) break;
            }
        }
    };
    for (int i=1;i<=n;++i){
        if (!dfs_num[i]) dfs(i);
    }

    if (SCCs.size()==1){
        cout<<"YES";
    }
    else{
        cout<<"NO\n";
        cout<<SCCs[0][0]<<" "<<SCCs[1][0];
    }

    return 0;
}





