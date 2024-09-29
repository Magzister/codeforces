#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

using namespace std;

void solve() {
    ll k; cin >> k;

    ll l = k;
    ll sqrt_ = ceil(sqrt(k)) + 1;
    ll r = sqrt_ * sqrt_;
    ll n;
    while (l < r) {
        n = (r + l) / 2;
        if (n - floor(sqrt(n)) < k) l = n + 1;
        else r = n;
    }
    cout << l << "\n";
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