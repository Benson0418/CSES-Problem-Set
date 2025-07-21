#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin>>n;
    if  (n==1){
        cout<<0;
        return 0;
    }
 
    vector<vector<int>> tree(n+1);
    for (int a,b,i=1;i<=n-1;++i){
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
 
    deque<int> que;
    que.pb(1);
    vector<int> visited(n+1,1);
    int z;
    while(!que.empty()){
        auto x=que.front();
        que.pop_front();
        if (!visited[x]) continue;
        visited[x]=0;
        if (que.empty()){
            z=x;
        }
        for (auto y:tree[x]){
            if (!visited[y]) continue;
            que.pb(y);
        }
    }
 
    deque<pair<int,int>> que1;
    que1.pb({z,0});
    visited[z]=1;
    int res=0;
    while (!que1.empty()){
        auto x=que1.front();
        que1.pop_front();
        res=max(res,x.S);
        for (auto& y:tree[x.F]){
            if (visited[y]) continue;
            que1.pb({y,x.S+1});
            visited[y]=1;
        }
    }
    cout<<res;
 
 
    return 0;
}
