#include <iostream>
#include <vector>


typedef long long ll;


void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    ll prefix_max = 0;
    ll prefix_sum = 0;
    ll result = 0;
    for (ll i = 0; i < n; i++)
    {
        prefix_sum += a[i];
        prefix_max = std::max(prefix_max, a[i]);
        if (prefix_sum - prefix_max == prefix_max)
        {
            result += 1;
        }
    }
    std::cout << result << std::endl;
}


int main() {
    ll t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}