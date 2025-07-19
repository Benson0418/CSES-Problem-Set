#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())

using LL = long long;
const int BASE = 131;
const int MOD = 1e9 + 9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t="#";
    cin>>s;
    for (char x:s){
        t+=x;
        t+='#';
    }

    int n=sz(t);

    vector<int> R(n,0);
    int center=0,right=0;

    for (int i=0;i<n;++i){
        int mirror=2*center-i;

        if (i<right){
            R[i]=min(right-i,R[mirror]);
        }

        while (i-R[i]-1>=0 && i+R[i]+1<n && t[i-R[i]-1]==t[i+R[i]+1]){
            ++R[i];
        }
        if (i+R[i]>right){
            center=i;
            right=i+R[i];
        }
    }

    int max_len=0,pos=0;
    for (int i=0;i<n;++i){
        if (R[i]>max_len){
            max_len=R[i];
            pos=i;
        }
    }
    string res;
    for (int i=pos-max_len;i<=pos+max_len;++i){
        if (t[i]!='#') res+=t[i];
    }
    cout<<res;
    return 0;
}

