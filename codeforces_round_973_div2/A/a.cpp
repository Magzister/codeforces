#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll n; cin >> n;
    ll x, y; cin >> x >> y;
    ll c = 0;
    ll sec_y = n / y;
    if (n % y) sec_y++;
    ll sec_x = n / x;
    if (n % x) sec_x++;
    cout << max(sec_x, sec_y) << "\n";
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