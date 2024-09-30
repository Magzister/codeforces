#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

vector<ll> zFunction(string s) {
    ll n = s.length();
    vector<ll> z(n, 0);
    ll l = 0, r = 0;
    for (ll i = 1; i < z.size(); i++)
    {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (z[i] + i < n && s[z[i] + i] == s[z[i]]) z[i]++;
        if (r < i + z[i] - 1) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    vector<ll> z = zFunction(s);

    for (ll i = 0; i < z.size(); i++)
    {
        cout << z[i] << " ";
    }
    cout << "\n";

    return 0;
}