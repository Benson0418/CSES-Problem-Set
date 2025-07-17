#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_tuple
#define eb emplace_back
#define pf pop_front
using LL = long long;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  LL n, m;
  cin >> n >> m;
  vector<vector<pair<LL, LL>>> graph(n + 1);
  vector<LL> dist(n + 1, -INF);

  for (LL a, b, c, i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    graph[a].eb(b, c);
  }

  dist[1] = 0;

  for (LL k = 1; k < n; ++k) {
    for (LL i = 1; i <= n; ++i) {
      if (dist[i] == -INF)
        continue;
      for (auto &X : graph[i]) {
        if (dist[X.F] < dist[i] + X.S) {
          dist[X.F] = dist[i] + X.S;
        }
      }
    }
  }
  vector<int> incycle(n + 1);
  for (LL i = 1; i <= n; ++i) {
    for (auto &X : graph[i]) {
      if (dist[i] == -INF)
        continue;
      if (dist[X.F] < dist[i] + X.S) {
        incycle[X.F] = 1;
      }
    }
  }

  deque<int> que;

  for (int i = 1; i <= n; ++i) {
    if (incycle[i]) {
      que.eb(i);
    }
  }
  LL x;
  while (!que.empty()) {
    x = que.front();
    que.pf();
    for (auto &X : graph[x]) {
      if (!incycle[X.F]) {
        incycle[X.F] = 1;
        que.eb(X.F);
      }
    }
  }

  cout << (incycle[n] ? -1 : dist[n]);

  return 0;
}
