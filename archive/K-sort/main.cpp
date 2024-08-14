#include <iostream>
#include <vector>


#define ll long long


int main() {
    ll t;
    std::cin >> t;

    while (t--)
    {
        ll n;
        std::cin >> n;
        std::vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        ll acc = 0;
        ll mx = 0;
        ll local_mx = 0;
        for (ll i = 0; i < n; i++)
        {
            local_mx = std::max(local_mx, a[i]);
            acc += local_mx - a[i];
            mx = std::max(local_mx - a[i], mx);
        }
        std::cout << acc + mx << std::endl;
    }
    
    return 0;
}