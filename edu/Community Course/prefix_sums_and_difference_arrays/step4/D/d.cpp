#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll n; cin >> n;
    vector<ll> s(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    
    ll ans = 0;
    vector<ll> c(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (i > 0)
        {
            c[i] += c[i - 1];
        }

        ll diff = s[i] - max(s[i] - c[i], (ll)1);
        if (i + s[i] + 1 < n) {
            c[i + s[i] + 1]--;
        }
        if (i + s[i] - diff + 1 < n) {
            c[i + s[i] - diff + 1]++;
        }

        if (c[i] > diff)
        {
            if (i + 2 < n) {
                c[i + 2] -= c[i] - diff;
            }
            if (i + 1 < n) {
                c[i + 1] += c[i] - diff;
            }
        }

        s[i] -= diff;
        if (s[i] > 1)
        {
            if (i + s[i] + 1 < n) {
                c[i + s[i] + 1]--;
            }
            if (i + 2 < n) {
                c[i + 2]++;
            }
            ans += s[i] - 1;
        }
    }
    cout << ans << "\n";
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