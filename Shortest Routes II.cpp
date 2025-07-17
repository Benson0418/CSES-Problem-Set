#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_tuple
#define eb emplace_back
#define pf pop_front
using LL=long long;
const LL INF=0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n,m,q;
    cin>>n>>m>>q;

    vector<vector<LL>> dist(n+1, vector<LL>(n+1, INF));
    for (LL i=1;i<=n;++i){
        dist[i][i]=0;
    }

    for (LL a,b,c,i=1;i<=m;++i){
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b], c);
        dist[b][a]=min(dist[b][a], c);
    }

    for (LL k=1;k<=n;++k){ //via
        for (LL i=1;i<=n;++i){ //from
            for (LL j=1;j<=n;++j){ //to
                dist[i][j]=min(dist[i][k]+dist[k][j], dist[i][j]);
            }
        }
    }

    for (LL a,b,i=1;i<=q;++i){
        cin>>a>>b;
        cout<<(dist[a][b]==INF?(LL)-1:dist[a][b])<<"\n";
    }

    return 0;
}

