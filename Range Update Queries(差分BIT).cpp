#include<bits/stdc++.h>
using namespace std;

struct Fenwick{
    vector<long long> bit;
    long long n;
    Fenwick(long long n):n(n),bit(n+1){}

    long long lowbit(long long x){return x&(-x);}

    void add(long long idx, long long x){
        for (;idx<=n;idx+=lowbit(idx)){bit[idx]+=x;}
    }

    void radd(long long a,long long b,long long u){
        if (b+1<=n){
            add(b+1,-u);
        }
        add(a,u);
    }

    long long query(long long idx){
        long long ans=0;
        for(;idx>0;idx-=lowbit(idx)){ans+=bit[idx];}
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,q;
    cin>>n>>q;
    Fenwick bit(n);
    vector<long long> X(n+1),D(n+1);
    for (long long i=1;i<=n;++i){
        cin>>X[i];
        D[i]=X[i]-X[i-1];
        bit.add(i,D[i]);
    }
    ++q;
    long long a=0,b=0,c=0;
    while (--q){
        cin>>a;
        if (a&1){
            cin>>a>>b>>c;
            bit.radd(a,b,c);
        }
        else{
            cin>>a;
            cout<<bit.query(a)<<"\n";
        }
    }




    return 0;
}
