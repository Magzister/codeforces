#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (n < 3) {
        cout << -1 << "\n";
        return;
    }

    sort(begin(a), end(a));
    ll a_k = a[n/2];

    ll ans = 0;
    if (2 * n * a_k - sum >= 0) {
        ans = 2 * n * a_k - sum + 1;
    }

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