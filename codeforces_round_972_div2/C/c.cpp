#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    vector<ll> b(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(begin(b), end(b));

    while(q--) {
        ll a; cin >> a;

        ll l = 0;
        ll r = m - 1;
        while(l < r) {
            ll mid = (ll)ceil((ld)(r + l) / 2);
            if (b[mid] < a) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }

        ll ans = 0;
        if (l == 0 && a < b[l]) {
            ll b_min = b[l];
            ans += a - 1;
            ans += b_min - a;
        }
        else if (l == m - 1) {
            ll b_max = b[l];
            ans += n - a;
            ans += a - b_max;
        }
        else {
            ll b_min = b[l];
            ll b_max = b[l + 1];
            ll bb = b_max - b_min;
            ans += bb / 2;
        }

        cout << ans << "\n";
    }
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