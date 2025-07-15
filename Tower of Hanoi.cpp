#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
 
    cout<<(int)pow(2,n)-1<<"\n";
    function<void(int,int,int,int)> Hanoi=[&](int x,int from,int via,int to){
        if (x==1) cout<<from<<" "<<to<<"\n";
        else {
            Hanoi(x-1,from,to,via);
            cout<<from<<" "<<to<<"\n";
            Hanoi(x-1,via,from,to);
        }
    };
    Hanoi(n,1,2,3);
 
    return 0;
