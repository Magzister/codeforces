#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll n, k; cin >> n >> k;
    if (k > n) {
        cout << n << "\n";
        return;
    }
    if (k == n) {
        cout << 1 << "\n";
        return;
    }
    if (k == 1) {
        cout << n << "\n";
        return;
    }
    ll cnt;
    ll ans = 0;
    while (n >= k) {
        cnt = k;
        while(cnt * k <= n) cnt *= k;
        n -= cnt;
        ans++;
    }
    if (n > 0) ans += n;
    cout << ans << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}