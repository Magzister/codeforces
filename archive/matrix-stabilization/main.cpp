#include <iostream>
#include <vector>
#include <algorithm>


typedef long long ll;


void solve(){
    ll n, m;
    std::cin >> n >> m;
    std::vector<std::vector<ll>> a(n, std::vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll u = 0, d = 0, r = 0, l = 0;
            if (i > 0)
            {
                u = a[i - 1][j];
            }
            if (i < n - 1)
            {
                d = a[i + 1][j];
            }
            if (j > 0)
            {
                l = a[i][j - 1];
            }
            if (j < m - 1)
            {
                r = a[i][j + 1];
            }
            ll mx = std::max({u, d, l, r});
            if (mx < a[i][j])
            {
                a[i][j] = mx;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    ll t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}