#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

void solve() {
    string s; cin >> s;
    ll ans = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        for (ll j = i; j < s.size(); j++)
        {
            bool isEqualPrefix = true;
            for (ll x = i; x <= j; x++)
            {
                if (s[x] != s[x - i]) {
                    isEqualPrefix = false;
                    break;
                }
            }
            bool isEqualSuffix = true;
            for (ll x = i; x <= j; x++)
            {
                if (s[x] != s[s.size() - 1 - (j - x)]) {
                    isEqualSuffix = false;
                    break;
                }
            }
            if (isEqualPrefix && !isEqualSuffix) {
                ans++;
            }
            if (!isEqualPrefix && isEqualSuffix) {
                ans++;
            }
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