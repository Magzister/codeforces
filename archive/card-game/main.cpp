#include <iostream>


typedef long long ll;


int game(ll a, ll b) {
    if (a > b)
    {
        return 1;
    }
    if (a == b)
    {
        return 0;
    }
    if (a < b)
    {
        return -1;
    }
}


int main() {
    ll t; std::cin >> t;
    while (t--)
    {
        ll a1, a2, b1, b2;
        std::cin >> a1 >> a2 >> b1 >> b2;
        ll ans = 0;
        if (game(a1, b1) + game(a2, b2) > 0)
        {
            ans += 1;
        }
        if (game(a1, b2) + game(a2, b1) > 0)
        {
            ans += 1;
        }
        if (game(a2, b1) + game(a1, b2) > 0)
        {
            ans += 1;
        }
        if (game(a2, b2) + game(a1, b1) > 0)
        {
            ans += 1;
        }
        std::cout << ans << std::endl;
    }
}