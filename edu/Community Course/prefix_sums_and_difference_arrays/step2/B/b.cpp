#include <iostream>
#include <vector>


typedef long long ll;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    ll n; std::cin >> n;
    std::vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::vector<ll> ps(n + 1);
    ps[0] = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        ps[i] = ps[i - 1] ^ a[i - 1];
    }

    ll q; std::cin >> q;
    while (q--)
    {
        ll l, r; std::cin >> l >> r;
        std::cout << (ps[r] ^ ps[l - 1]) << std::endl;
    }
    
    return 0;
}