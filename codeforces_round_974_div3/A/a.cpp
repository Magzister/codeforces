#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll coins = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] >= k) {
            coins += a[i];
        }
        if (a[i] == 0 && coins > 0) {
            coins--;
            ans++;
        }
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