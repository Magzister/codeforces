#include <iostream>
#include <vector>


typedef long long ll;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    ll n, m; std::cin >> n >> m;
    std::vector<std::vector<ll>> a(n, std::vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<ll>> ps(n + 1, std::vector<ll>(m + 1, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + a[i][j];
        }
    }

    ll q; std::cin >> q;
    while (q--)
    {
        ll lx, ly, rx, ry; std::cin >> lx >> ly >> rx >> ry;
        lx--;
        ly--;
        ll ans = ps[rx][ry] - ps[lx][ry] - ps[rx][ly] + ps[lx][ly];
        std::cout << ans << std::endl;
    }
    
    return 0;
}