#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 1e6;
    vector<int> isP(N+1, 1);
    vector<int> Primes;

    isP[0] = 0;
    isP[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (isP[i]) Primes.push_back(i);
        for (int j = 0; j < (int)Primes.size() && 1LL*i*Primes[j] <= N; j++) {
            isP[i * Primes[j]] = 0;
            if (i % Primes[j] == 0) break;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int ans = 1;
        int tmp = x;

        for (int p : Primes) {
            if (1LL*p*p > tmp) break;
            if (tmp % p == 0) {
                int cnt = 0;
                while (tmp % p == 0) {
                    tmp /= p;
                    cnt++;
                }
                ans *= (cnt + 1);
            }
        }
        if (tmp > 1) ans *= 2;

        cout << ans << "\n";
    }
    return 0;
}

