#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    ll b1, b2; cin >> b1 >> b2;
    ll a; cin >> a;
    ll ans = 0;
    ll max_b = max(b1, b2);
    ll min_b = min(b1, b2);
    if (a < b1 && a < b2) {
        ans += a - 1;
        ans += min_b - a;
    }
    else if (a > b1 && a > b2) {
        ans += n - a;
        ans += a - max_b;
    }
    else {
        ll bb = max_b - min_b;
        ans += bb / 2;
    }
    cout << ans << "\n";
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