#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> da_q(n, 0);
    while (q--)
    {
        ll l, r; cin >> l >> r;
        l--;
        da_q[l]++;
        if (r < n)
        {
            da_q[r]--;
        }
    }

    for (ll i = 1; i < n; i++)
    {
        da_q[i] += da_q[i - 1];
    }

    sort(begin(a), end(a), greater<ll>());
    sort(begin(da_q), end(da_q), greater<ll>());

    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i] * da_q[i];
    }

    cout << sum << "\n";

    return 0;
}