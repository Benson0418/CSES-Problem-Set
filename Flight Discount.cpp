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
const LL INF = 0x3f3f3f3f3f3f3f3f;
#define g0(X) (get<0>(X))
#define g1(X) (get<1>(X))
#define g2(X) (get<2>(X))
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n,m;
    cin>>n>>m;
    vector<vector<pair<LL,LL>>> graph(n+1); // target price
    vector<pair<LL,LL>> dist(n+1, {INF,INF}); // not_used used
    priority_queue<tuple<LL,LL,LL>,vector<tuple<LL,LL,LL>>,greater<tuple<LL,LL,LL>>> minpq; // dist vertex used
    vector<pair<LL,LL>> locked(n+1); // not_used used

    for (LL a,b,c,i=1;i<=m;++i){
        cin>>a>>b>>c;
        graph[a].eb(b,c);
    }

    dist[1]={0,0};
    minpq.push(mp(0,1,0));
    minpq.push(mp(0,1,1));

    while (!minpq.empty()){
        auto X=minpq.top();
        minpq.pop();
        if (!(!g2(X) && !locked[g1(X)].F || g2(X) && !locked[g1(X)].S)) continue;
        if (g2(X)){
            locked[g1(X)].S=1;
            dist[g1(X)].S=min(dist[g1(X)].S, g0(X));
            for (auto& Y:graph[g1(X)]){
                if (!locked[Y.F].S){
                    minpq.push(mp(dist[g1(X)].S+Y.S,Y.F,1));
                }
            }
        }
        else{
            locked[g1(X)].F=1;
            dist[g1(X)].F=min(dist[g1(X)].F, g0(X));
            for (auto& Y:graph[g1(X)]){
                if (!locked[Y.F].F){
                    minpq.push(mp(dist[g1(X)].F+Y.S,Y.F,0));
                }
                if (!locked[Y.F].S){
                    minpq.push(mp(dist[g1(X)].F+Y.S/2,Y.F,1));
                }
            }
        }
    }



  cout<<dist[n].S;

  return 0;
}
