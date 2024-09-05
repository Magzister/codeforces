#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> unique(1000001, 0);
    vector<ll> w_w_d(n);
    vector<ll> w;
    for (ll i = 0; i < n; i++)
    {
        cin >> w_w_d[i];
        if (unique[w_w_d[i]] == 0) {
            unique[w_w_d[i]] = 1;
            w.push_back(w_w_d[i]);
        }
    }
    n = w.size();
    if (m >= k) {
        cout << 1000000 - k + 1 << "\n";
        return 0;
    }
    if (n + m < k) {
        cout << 0 << "\n";
        return 0;
    }

    sort(begin(w), end(w));
    vector<ll> da(n, 0);
    for (ll i = 1; i < n; i++)
    {
        da[i] = w[i] - w[i - 1] - 1;
    }
    vector<ll> ps(n, 0);
    for (ll i = 1; i < n; i++)
    {
        ps[i] = da[i] + ps[i - 1];
    }

    ll ans = 0;
    ll l_number = k - m;
    ll start = l_number - 1;
    for (ll i = start; i < n; i++)
    {
        ll l_free = ps[i] - ps[i - l_number + 1];
        if (l_free > m) continue;
        if (l_free == m) {
            ans++;
            continue;
        }
        if (l_free < m) {
            ll rest = m - l_free;
            ll next_space = 0;
            if (i < n - 1) next_space = da[i + 1];
            else {
                if (1000000 - w[i] < rest) next_space = 1000000 - w[i];
                else next_space = rest;
            }
            ll add;
            if (next_space >= rest) add = rest;
            else add = next_space;
            if (w[i] < k) {
                if (w[i] + add >= k) {
                    add = w[i] + add - k + 1;
                }
                else add = 0;
                ans += add;
            }
            else ans += 1 + add;
        }
    }

    cout << ans << "\n";

    return 0;
}