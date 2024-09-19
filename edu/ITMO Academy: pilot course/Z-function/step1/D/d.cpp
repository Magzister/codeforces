#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

typedef long long ll;

using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    ll ans = 0;
    ll start = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (start < i) start = i;
        for (ll j = i; j < s.size(); j++)
        {
            if (j < start + t.size() - 1) {
                ans++;
                continue;
            }
            bool match = false;
            for (ll k = start; k <= j - t.size() + 1; k++)
            {
                match = true;
                for (ll x = 0; x < t.size(); x++)
                {
                    if (s[k + x] != t[x]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    break;
                }
                else {
                    start++;
                }
            }
            if (match) {
                break;
            }
            else {
                ans++;
            }
        }
    }


    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll q; cin >> q;
    while (q--)
    {
        solve();
    }

    return 0;
}