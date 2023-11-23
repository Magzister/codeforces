#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = -1;
    for (int k = 1; k <= n; k++) {
        if (n % k == 0) {
            ll mx = -1e18, mn = 1e18;
            for (int i = 0; i < n; i += k) {
                ll sm = 0;
                for (int j = i; j < i + k; j++) {
                    sm += a[j];
                }
                mx = max(mx, sm);
                mn = min(mn, sm);
            }
            ans = max(ans, mx - mn);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
