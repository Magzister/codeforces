#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
typedef long double ld;

using namespace std;

int odd_count(int x) {
    if (x%2) {
        return x/2+1;
    }
    return x/2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--)
    {
        ll n, k; cin >> n >> k;
        ll n_count = odd_count(n);
        ll k_count = odd_count(n-k);
        if ((n_count - k_count) % 2) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }

    return 0;
}