#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> da(n, vector<ll>(m, 0));

    ll q; cin >> q;
    while (q--)
    {
        ll lx, ly, rx, ry, d;
        cin >> lx >> ly >> rx >> ry >> d;
        lx--;
        ly--;
        da[lx][ly] += d;
        if (rx < n && ry < m) {
            da[rx][ry] += d;
        }
        if (rx < n) {
            da[rx][ly] -= d;
        }
        if (ry < m) {
            da[lx][ry] -= d;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) {
                continue;
            }

            if (i > 0 && j > 0) {
                da[i][j] += da[i - 1][j] + da[i][j - 1] - da[i - 1][j - 1];
            }
            else if (i > 0) {
                da[i][j] += da[i - 1][j];
            }
            else if (j > 0) {
                da[i][j] += da[i][j - 1];
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << a[i][j] + da[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}