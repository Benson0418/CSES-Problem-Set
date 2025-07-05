#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<string> grid(n);
    for (auto& x:grid) cin>>x;
    vector<vector<int>> sc(n+1, vector<int>(n+1,0));

    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (grid[i-1][j-1]=='*') ++sc[i][j];
            sc[i][j]+=sc[i][j-1];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=n;j>0;--j){
            sc[i][j]+=sc[i-1][j];
        }
    }

    ++q;
    int x1,y1,x2,y2;
    while (--q){
        cin>>y1>>x1>>y2>>x2;
        cout<<sc[y2][x2]-sc[y1-1][x2]-sc[y2][x1-1]+sc[y1-1][x1-1]<<"\n";
    }

    return 0;
}

