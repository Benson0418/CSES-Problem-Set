#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin>>n;
    if (n==1){
        cout<<0;
        return 0;
    }
    vector<int> pa(n+1);
    vector<int> indeg(n+1);
    vector<int> res(n+1);
    for (int a,i=2;i<=n;++i){
        cin>>a;
        ++indeg[a];
        pa[i]=a;
    }


    deque<int> que;
    for (int i=2;i<=n;++i){
        if (!indeg[i]){
            que.pb(i);
        }
    }

    int e;
    while (!que.empty()){
        e=que.front();
        que.pop_front();
        if (!pa[e]) continue;
        --indeg[pa[e]];
        res[pa[e]]+=1+res[e];
        if (!indeg[pa[e]]){
            que.pb(pa[e]);
        }
    }
    for(int i=1;i<=n;++i){
        cout<<res[i]<<" ";
    }



    return 0;
}

