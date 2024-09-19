#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

typedef long long ll;

using namespace std;

vector<ll> getReverse(vector<ll> a) {
    vector<ll> res(a.size());
    for (ll i = 0; i < a.size(); i++)
    {
        res[a[i] - 1] = i + 1;
    }
    return res;
}

vector<ll> getComposition(vector<ll> a, vector<ll> b) {
    vector<ll> res(a.size());
    for (ll i = 0; i < a.size(); i++)
    {
        res[i] = b[a[i] - 1];
    }
    return res;
}

ll getPermutationSum(vector<ll> a) {
    ll res = 0;
    for (ll i = 0; i < a.size(); i++)
    {
        res += (i + 1) * a[i];
    }
    return res;
}

void solve() {
    map<pair<int, int>, ll> cache;
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (ll i = 1; i < n; i++)
    {
        a[i] = getComposition(a[i - 1], a[i]);
    }

    vector<vector<ll>> reverse(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        reverse[i] = getReverse(a[i]);
    }

    ll q; cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll l, r; cin >> l >> r;
        pair<int, int> lr = make_pair(l, r);
        if (cache.find(lr) != cache.end()) {
            cout << cache[lr] << "\n";
            continue;
        }
        l -= 2;
        r--;
        vector<ll> res_a(m);
        if (l >= 0) {
            res_a = getComposition(reverse[l], a[r]);
        }
        else {
            res_a = a[r];
        }
        ll res = getPermutationSum(res_a);
        cache[make_pair(l += 2, ++r)] = res;
        cout << res << "\n";
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