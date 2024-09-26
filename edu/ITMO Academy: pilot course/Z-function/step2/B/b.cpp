#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin >> t;
    while (t--)
    {
        ll ans = 0;
        ll k, j; cin >> k >> j;
        if (j > 0) {
            ans = (j & -j) - 1;
        }
        cout << ans << "\n";
    }

    return 0;
}