#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int n;
    vector<int> tree;

    SegmentTree(const vector<int>& H):tree(H.size()*4), n(H.size()-1){
        build(1,1,n,H);
    }
    void build(int node, int l,int r,const vector<int>& H){
        if (l==r){
            tree[node]=H[l];
            return;
        }
        int mid=(l+r)/2;
        build(node<<1,l,mid,H);
        build(node<<1|1,mid+1,r,H); //等效為node*2+1，1-based的右子樹
        tree[node]=max(tree[node<<1], tree[node<<1|1]);
    }

    int query(int node, int l, int r, int x){
        if (tree[node]<x) return 0;
        if (l==r){
            tree[node]-=x;
            return l;
        }
        int mid=(l+r)/2;
        int res;
        if (tree[node<<1]>=x){
            res=query(node<<1,l,mid,x);
        }
        else{
            res=query(node<<1|1,mid+1,r,x);
        }
        tree[node]=max(tree[node<<1],tree[node<<1|1]);
        return res;
    }





};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> H(n+1);
    for (int i=1;i<=n;++i){
        cin>>H[i];
    }
    SegmentTree Tree(H);

    ++m;
    int r;
    while (--m){
        cin>>r;
        cout<<Tree.query(1,1,n,r)<<" ";
    }

    return 0;
}


