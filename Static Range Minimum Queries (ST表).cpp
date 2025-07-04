#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,q;
    cin>>n>>q;
    vector<int> arr(n+1);
    for (int i=1;i<=n;++i){
        cin>>arr[i];
    }
 
    int LOG = __lg(n)+1;
    vector<vector<int>> ST(n+1, vector<int>(LOG));
 
    for (int i=1;i<=n;++i){
        ST[i][0]=arr[i];
    }
 
    for (int j=1;(1<<j)<=n;++j){
        for (int i=1;i+(1<<j)-1<=n;++i){
            ST[i][j]=min(ST[i][j-1], ST[i+(1<<(j-1))][j-1]);
        }
    }
 
    int k=0;
 
    for (int a,b,i=0;i<q;++i){
        cin>>a>>b;
        k=__lg(b-a+1);
        cout<< min(ST[a][k], ST[b-(1<<k)+1][k])<<"\n";
    }
 
 
 
    return 0;
}
