#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
#define pb push_back
const LL MOD = 1e9+7;
const int INF = 0x3f3f3f3f;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> rel(n+1);
    for(int i=0;i<m;++i){
        cin>>a>>b;
        rel[a].pb(b);
        rel[b].pb(a);
    }
    vector<int> color(n+1);
    deque<pair<int,int>> que;
    pair<int,int> X;
    for (int i=1;i<=n;++i){
        if (!color[i]){
            color[i]=1;
            que.clear();
            que.pb({i,1});
            while (!que.empty()){
                X=que.front();
                que.pop_front();
                for (auto& x:rel[X.fi]){
                    if (color[x]==X.se){
                        cout<<"IMPOSSIBLE";
                        return 0;
                    }
                    else if (color[x]==0){
                        color[x]=3-X.se;
                        que.pb({x,3-X.se});
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;++i){
        cout<<color[i]<<" ";
    }



    return 0;
}

