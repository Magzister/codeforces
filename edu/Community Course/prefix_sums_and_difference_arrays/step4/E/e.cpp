#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> da_a(n, 0);
    for (ll i = 1; i < n; i++)
    {
        da_a[i] = a[i] - a[i - 1];
    }

    vector<vector<ll>> op(m, vector<ll>(3));
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            cin >> op[i][j];
        }
    }

    vector<ll> da_m(m, 0);
    while (k--)
    {
        ll x, y; cin >> x >> y;
        da_m[x - 1]++;
        if (y < m)
        {
            da_m[y]--;
        }
    }

    for (ll i = 1; i < m; i++)
    {
        da_m[i] += da_m[i - 1];
    }

    for (ll i = 0; i < m; i++)
    {
        ll l = op[i][0] - 1;
        ll r = op[i][1];
        ll d = op[i][2];
        da_a[l] += d * da_m[i];
        if (r < n)
        {
            da_a[r] -= d * da_m[i];
        }
    }

    a[0] += da_a[0];
    cout << a[0] << " ";
    for (ll i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + da_a[i];
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}