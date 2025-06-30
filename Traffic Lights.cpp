#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int x,n,temp;
    cin>>x>>n;
    vector<int> P(n);
    for (auto& z:P) cin>>z;
    multiset<int> S,pos;
    S.insert(x);
    pos.insert(0);
    pos.insert(x);
    for (auto& z:P){
        auto it=pos.lower_bound(z);
        auto rit = it--;
        temp=(*rit)-(*it);
        S.erase(S.find(temp));
        S.insert(*rit-z);
        S.insert(z-*it);
        pos.insert(z);
        cout<<*S.rbegin()<<" ";
    }
 
 
    return 0;
}
