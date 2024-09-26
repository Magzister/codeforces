#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

vector<ll> z_func(string s) {
    ll len = s.size();
    vector<ll> v;
    v.push_back(0);
    for (ll i = 1; i < len; i++) {
        ll c = 0;
        while (s[i+c] == s[c] && i + c < len) {
            c += 1;
        }
        v.push_back(c);
    }
    return v;
}

void solve() {
    ll n; cin >> n;
    vector<ll> z(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> z[i];
    }

    if (z[0] != 0) {
        cout << "!" << "\n";
        return;
    }

    for (ll i = 1; i < n; i++)
    {
        if (z[i] > n - i) {
            cout << "!" << "\n";
            return;
        }
    }


    string s = "a";
    for (ll i = 1; i < n; i++)
    {
        s += "_";
    }


    string al = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ll acc = 1;
    for (ll i = 1; i < n; i++)
    {
        if (z[i] == 0) {
            if (s[i] == '_') {
                s[i] = al[acc];
                acc++;
            }
        } else {
            for (ll j = 0; j < z[i]; j++)
            {
                s[i + j] = s[j];
            }
        }
    }

    if (s.length() == n) {
        vector<ll> z_res = z_func(s);
        for (ll i = 0; i < n; i++) {
            if (z_res[i] != z[i]) {
                s = "!";
                break;
            }
        }
    }
    else {
        s = "!";
    }

    cout << s << "\n";

    return;
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