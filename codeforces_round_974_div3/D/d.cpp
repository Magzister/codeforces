#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

typedef long long ll;

using namespace std;

void solve() {
    ll n, d, k; cin >> n >> d >> k;
    vector<ll> da(n + 1, 0);
    for (ll i = 0; i < k; i++)
    {
        ll l, r;
        cin >> l >> r;
        l -= d - 1;
        if (l < 1) l = 1;
        da[l]++;
        r++;
        if (r <= n) da[r]--;
    }
    for (ll i = 1; i <= n; i++)
    {
        da[i] += da[i - 1];
    }
    ll max_i = 1;
    ll min_i = 1;
    for (ll i = 2; i <= n - d + 1; i++)
    {
        if (da[i] < da[min_i]) min_i = i;
        if (da[i] > da[max_i]) max_i = i;
    }

    cout << max_i << " " << min_i << "\n";

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