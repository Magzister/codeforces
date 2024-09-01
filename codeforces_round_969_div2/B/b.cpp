#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    ll max_a = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    for (ll i = 0; i < m; i++)
    {
        char ch; cin >> ch;
        ll l, r; cin >> l >> r;
        if (max_a >= l && max_a <= r)
        {
            if (ch == '+') max_a++;
            else max_a--;
        }
        cout << max_a << " ";
    }
    cout << "\n";

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