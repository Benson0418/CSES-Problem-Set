#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
const LL MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
void swap1(int &A,int &B){
    if (A>B){
        swap(A,B);
    }
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int a,b,y,z,w,temp;
    cin>>a>>b;
    swap1(a,b);
    vector<vector<int>> M(a+1,vector<int>(b+1, INF));
    for (int i=0;i<=min(a,b);++i){
        M[i][i]=0;
    }
    for (int i=1;i<=a;++i){
        for (int j=i+1;j<=b;++j){
            for (int x=1;x<=j/2;++x){
                y = i;
                temp = y;
                z = x;
                w = j-x;
                swap1(temp, z);
                swap1(y,w);
                M[i][j]=min(M[i][j], M[y][w]+M[temp][z]+1);
            }
            for (int x=1;x<=i/2;++x){
                y = j;
                temp = y;
                z = x;
                w = i-x;
                swap1(temp, z);
                swap1(y,w);
                M[i][j]=min(M[i][j], M[y][w]+M[temp][z]+1);            }
        }
    }
    cout<<M[a][b];
 
 
    return 0;
}
