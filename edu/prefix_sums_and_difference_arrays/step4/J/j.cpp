#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll N = 1000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> w(n);
    vector<ll> ps(N, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
        ps[w[i]] = 1;
    }

    for (ll i = 1; i < N; i++)
    {
        ps[i] += ps[i - 1];
    }

    ll ans = 0;
    for (ll i = k; i < N; i++) {
        if (ps[i] - ps[i - k] >= k - m) {
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}