#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll l, r; cin >> l >> r;
    ll n = r - l + 1;
    if (n % 2 == 0)
    {
        cout << n / 4 << "\n";
    }
    else
    {
        if (l % 2 == 0)
        {
            cout << n / 4 << "\n";
        }
        else
        {
            cout << (n / 2 + 1) / 2 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}