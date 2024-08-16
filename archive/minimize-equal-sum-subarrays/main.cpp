#include <iostream>
#include <vector>


typedef long long ll;


void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }

    for (ll i = 1; i < n; i++)
    {
        std::cout << p[i] << " ";
    }
    std::cout << p[0] << std::endl;
}


int main() {
    ll t;
    std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}