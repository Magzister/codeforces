#include <iostream>
#include <vector>
#include <algorithm>

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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> ps(n, vector<ll>(m));
    ps[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ps[i][j] = a[i][ps[i - 1][j] - 1];
        }
        // a[i] = getComposition(a[i - 1], a[i]);
    }

    vector<vector<ll>> reverse(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            reverse[i][ps[i][j] - 1] = j + 1;
        }
        // reverse[i] = getReverse(a[i]);
    }

    ll q; cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll l, r; cin >> l >> r;
        l -= 2;
        r--;
        ll res = 0;
        vector<ll> res_a(m);
        if (l >= 0) {
            for (ll j = 0; j < m; j++)
            {
                res += (j + 1) * ps[r][reverse[l][j] - 1];
            }
            // res_a = getComposition(reverse[l], a[r]);
        }
        else {
            for (ll j = 0; j < m; j++)
            {
                res += (j + 1) * ps[r][j];
            }
            // ll res = getPermutationSum(res_a);
        }
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