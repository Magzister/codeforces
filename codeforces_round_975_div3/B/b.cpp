#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;

using namespace std;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<ll> k(q);
    for (ll i = 0; i < q; i++)
    {
        cin >> k[i];
    }

    map<ll, ll> cnt;
    for (ll i = 0; i < n; i++)
    {
        ll key = (i + 1) * (n - i - 1) + i;
        if (cnt.find(key) == cnt.end()) {
            cnt[key] = 1;
        } else {
            cnt[key]++;
        }

        if (i < n - 1) {
            key = (i + 1) * (n - i - 1);
            if (cnt.find(key) == cnt.end()) {
                cnt[key] = x[i + 1] - x[i] - 1;
            }
            else {
                cnt[key] += x[i + 1] - x[i] - 1;
            }
        }
    }

    for (ll i = 0; i < q; i++)
    {
        if (cnt.find(k[i]) == cnt.end()) {
            cout << 0 << " ";
        } else {
            cout << cnt[k[i]] << " ";
        }
    }
    cout << "\n";

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