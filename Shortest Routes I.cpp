#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
#define pb push_back
const LL MOD = 1e9+7;
const LL INF = 0x3f3f3f3f3f3f3f3f;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n,m;
    cin>>n>>m;

    vector<LL> dist(n+1, INF);
    dist[1]=0;
    vector<vector<pair<LL,LL>>> graph(n+1);

    for (LL a,b,c,i=0;i<m;++i){
        cin>>a>>b>>c;
        graph[a].pb({c,b});
    }

    vector<int> locked(n+1);

    priority_queue<pair<LL,LL>, vector<pair<LL,LL>>, greater<pair<LL,LL>>> minpq;

    minpq.push({0,1});

    pair<LL,LL> X;
    while (!minpq.empty()){
        X=minpq.top();
        minpq.pop();
        if (locked[X.se]) continue;
        locked[X.se]=1;
        dist[X.se]=min(dist[X.se], X.fi);
        for (auto& y:graph[X.se]){
            if (locked[y.se]) continue;
            minpq.push({X.fi+y.fi,y.se});
        }
    }
    for (LL i=1;i<=n;++i){
        cout<<dist[i]<<" ";
    }

    return 0;

}





