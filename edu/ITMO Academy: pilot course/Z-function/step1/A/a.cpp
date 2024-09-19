#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

void solve() {
    string s; cin >> s;
    ll ans = 1;
    for (ll i = 1; i < s.size(); i++)
    {
        bool isPalindrome = true;
        for (ll j = 0; j <= i / 2; j++)
        {
            if (s[j] != s[i - j]) {
                isPalindrome = false;
            }
        }
        if (isPalindrome) {
            ans = i + 1;
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