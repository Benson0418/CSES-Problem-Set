#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_tuple
#define eb emplace_back

using LL = long long;
const LL INF = 0x3f3f3f3f3f3f3f3f;
#define g0(X) (get<0>(X))
#define g1(X) (get<1>(X))
#define g2(X) (get<2>(X))
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text,patt;
    cin>>text>>patt;
    vector<int> pi(patt.size());

    int i=1,pl=0;
    while (i<(int)patt.size()){
        if (patt[pl]==patt[i]){
            ++pl;
            pi[i]=pl;
            ++i;
        }
        else{
            if (pl==0){
                pi[i]=0;
                ++i;
            }
            else{
                pl=pi[pl-1];
            }
        }
    }


    i=0;
    int j=0,cnt=0;
    while (i<(int)text.size()){
        if (text[i]==patt[j]){
            ++i;
            ++j;
        }
        else if (j>0){
            j=pi[j-1];
        }
        else{
            ++i;
        }

        if (j==(int)patt.size()){
            ++cnt;
            j=pi[j-1];
        }
    }
    cout<<cnt;
    return 0;
}

