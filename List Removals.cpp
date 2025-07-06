#include<bits/stdc++.h>
using namespace std;

struct Fenwick{
    int n;
    vector<int> bit;
    const vector<int>& E;

    Fenwick(int n,const vector<int>& X):n(n+1), bit(n+2), E(X){
        for (int i=1;i<=n;++i){
            for (int j=i;j<=n;j+=lowbit(j)){++bit[j];}
        }
    }

    int lowbit(int x){return x&-x;}

    int query(int idx){
        int psum=0;
        for (;idx>0;idx-=lowbit(idx))psum+=bit[idx];
        return psum;
    }

    void del(int idx){
        for (;idx<=n;idx+=lowbit(idx))--bit[idx];
        return;
    }

    int find_nth(int k){
        int l=1,r=n,mid=0;
        while (l<r){
            mid=(l+r)/2;
            if (query(mid)>=k){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        del(l);
        return E[l];
    }


};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> X(n+1);
    for (int i=1;i<=n;++i){
        cin>>X[i];
    }
    Fenwick tree(n, X);

    for (int p,i=1;i<=n;++i){
        cin>>p;
        cout<<tree.find_nth(p)<<"\n";
    }


    return 0;
}


