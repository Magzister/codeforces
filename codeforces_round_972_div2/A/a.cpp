#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

void solve() {
    ll n; cin >> n;
    ll div = n / 5;
    ll mod = n % 5;
    string base = "aeiou";
    string ans = "";
    for (ll i = 0; i < base.length(); i++)
    {
        for (ll j = 0; j < div; j++)
        {
            ans += base[i];
        }
        if (mod > 0) {
            ans += base[i];
            mod--;
        }
    }
    cout << ans << "\n";
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