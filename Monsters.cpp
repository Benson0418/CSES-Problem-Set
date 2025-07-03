#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
#define pb push_back
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
#define mt make_tuple
#define ww(z) get<0>(z)
#define wx(z) get<1>(z)
#define wy(z) get<2>(z)


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for (auto& x:grid) cin>>x;
    vector<vector<int>> step(n,vector<int>(m, INF));
    int px=0,py=0;
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,-1,1}; //D U L R
    deque<tuple<int,int,int>> que;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (grid[i][j]=='M'){
                que.pb(mt(0,i,j));
            }
            else if (grid[i][j]=='A'){
                px=i,py=j;
            }
        }
    }




    tuple<int,int,int> X;
    int nx=0,ny=0;

    while (!que.empty()){
        X=que.front();
        que.pop_front();
        if (step[wx(X)][wy(X)]!=INF) continue;
        step[wx(X)][wy(X)]=ww(X);
        for (int i=0;i<=3;++i){
            nx=wx(X)+dx[i];
            ny=wy(X)+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && step[nx][ny]==INF &&(grid[nx][ny]=='.' || grid[nx][ny]=='A')){
                que.pb(mt(ww(X)+1,nx,ny));
            }
        }
    }

    int res=0;
    vector<vector<int>> pstep(n,vector<int>(m, INF));
    vector<vector<char>> route(n,vector<char>(m, '0'));
    bool flag;
    char e;
    deque<tuple<int,int,int,char>> fque;
    fque.pb(mt(0,px,py,'X'));
    tuple<int,int,int,char> Y;


    while (!fque.empty()){
        Y=fque.front();
        fque.pop_front();
        if (pstep[wx(Y)][wy(Y)]!=INF) continue;
        pstep[wx(Y)][wy(Y)]=ww(Y);
        route[wx(Y)][wy(Y)]=get<3>(Y);
        if (wx(Y)==0 || wx(Y)==n-1 || wy(Y)==0 || wy(Y)==m-1){
            cout<<"YES\n";
            cout<<ww(Y)<<"\n";
            vector<char> ans;
            int rx=wx(Y),ry=wy(Y);
            while (route[rx][ry]!='X'){
                ans.pb(route[rx][ry]);
                if (route[rx][ry]=='D'){--rx;}
                else if (route[rx][ry]=='U'){++rx;}
                else if (route[rx][ry]=='L'){++ry;}
                else {--ry;}
            }
            reverse(all(ans));
            for (auto& x:ans) cout<<x;
            return 0;
        }
        for (int i=0;i<=3;++i){
            nx=wx(Y)+dx[i];
            ny=wy(Y)+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && pstep[nx][ny]==INF && grid[nx][ny]=='.' && step[nx][ny]>ww(Y)+1){
                if (i==0) {e='D';}
                else if (i==1) {e='U';}
                else if (i==2) {e='L';}
                else {e='R';}
                fque.pb(mt(ww(Y)+1,nx,ny,e));
            }
        }
    }

    cout<<"NO";

    return 0;

}






