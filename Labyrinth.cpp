#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
const LL MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for (auto& x:grid) cin>>x;

    int xa=0,ya=0,xb=0,yb=0,c=2;
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1}; //D R U L
    vector<char> D={'D','R','U','L'};
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (grid[i][j]=='A'){
                --c;
                xa=i;
                ya=j;
                if (!c) break;
            }
            else if (grid[i][j]=='B'){
                --c;
                xb=i;
                yb=j;
                if (!c) break;
            }
        }
    }
    vector<vector<char>> dir(n,vector<char>(m, '0'));
    deque<pair<int,int>> que;
    que.push_back({xa,ya});
    pair<int,int> X;
    dir[xa][ya]='X';
    int nx,ny;
    while (!que.empty()){
        X=que.front();
        que.pop_front();
        for (int i=0;i<=3;++i){
            nx=X.f+dx[i];
            ny=X.s+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && dir[nx][ny]=='0'){
                que.push_back({nx,ny});
                dir[nx][ny]=D[i];
            }
        }
    }

//    for (int i=0;i<n;++i){
//        for (int j=0;j<m;++j){
//            cout<<dir[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    if (dir[xb][yb]!='0') {
        cout<<"YES\n";
        string res;
        int x=xb, y=yb;
        while (x!=xa || y!=ya) {
            char di = dir[x][y];
            res.push_back(di);

            if (di=='D') x--;
            else if (di=='R') y--;
            else if (di=='U') x++;
            else if (di=='L') y++;
        }
        reverse(all(res));
        cout<<res.size()<<"\n"<<res<<"\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
