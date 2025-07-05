#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int n;
    vector<int> tree;

    SegmentTree(int n):n(n), tree(4*n){}

    void build(const vector<int>&a, int node, int l,int r){
        if (l==r){
            tree[node]=a[l];
            return;
        }
        int mid=(l+r)/2;
        build(a,node*2,l,mid);
        build(a,node*2+1,mid+1,r);
        tree[node]=min(tree[node*2], tree[node*2+1]);
        return;
    }
    void update(int node, int l, int r, int pos, int val){
        if (l==r){
            tree[node]=val;
            return;
        }
        int mid=(l+r)/2;
        if (pos<=mid) update(node*2, l, mid, pos, val);
        else update(node*2+1, mid+1,r, pos, val);
        tree[node]=min(tree[node*2],tree[node*2+1]);
        return;
    }

    int query(int node, int l,int r,int ql,int qr){
        if (qr<l || ql>r) return INT_MAX;
        if (ql<=l && r<=qr) return tree[node];
        int mid=(l+r)/2;
        return min(query(node*2,l,mid,ql,qr),query(node*2+1,mid+1,r,ql,qr));
    }



};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<int> X(n+1);
    for (int i=1;i<=n;++i){
        cin>>X[i];

    }
    SegmentTree E(n+1);
    E.build(X,1,1,n);

    for (int k,a,b,i=0;i<q;++i){
        cin>>k>>a>>b;
        if (k==1){
            E.update(1,1,n,a,b);
        }
        else{
            cout<<E.query(1,1,n,a,b)<<"\n";
        }
    }

    return 0;
}

