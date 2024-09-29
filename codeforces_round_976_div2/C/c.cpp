#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve() {
    ll b, c, d; cin >> b >> c >> d;
    ll l = 0;
    ll r = 2305843009213693952;
    ll m;
    while (l < r) {
        m = (r + l) / 2;
        if ((m | b) - (m & c) < d) l = m + 1;
        else r = m;
    }
    ll ans;
    if ((l | b) - (l & c) == d) ans = l;
    else ans = -1;
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