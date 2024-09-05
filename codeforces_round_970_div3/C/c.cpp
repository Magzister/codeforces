#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll l, r; cin >> l >> r;
    ll diff = r - l;
    ll acc = 1;
    while (l + acc <= r)
    {
        l += acc;
        acc++;
    }
    cout << acc << "\n";
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