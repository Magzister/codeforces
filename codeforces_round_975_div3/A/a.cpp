#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll max_red_count = n / 2 + 1 ? n % 2 : n / 2;
    ll max_red_odd = 0;
    ll max_red_even = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0) {
            if (a[i] > max_red_even) max_red_even = a[i];
        } else {
            if (a[i] > max_red_odd) max_red_odd = a[i];
        }
    }
    ll max_red = max(max_red_even, max_red_odd);

    ll ans;
    if (n % 2 == 0) {
        ans = max_red + n / 2;
    } else {
        ans = max(max_red_even + n / 2 + 1, max_red_odd + n / 2);
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