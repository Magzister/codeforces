#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

ll get_count(ll n) {
    return n * (n + 1) / 2;
}

void solve() {
    string s, t; cin >> s >> t;
    ll ans = 0;
    vector<int> a;
    int ind = s.size() - t.size();
    for (int i = 0; i <= ind; i++)
    {

        bool match = true;
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != t[j])
            {
                match = false;
                break;
            }
        }
        if (match) {
            a.push_back(i);
        }
    }
    if (a.size() > 0) {
        int r = a[0] + t.size() - 1;
        int l = a[0];
        ll n = r;
        ans += get_count(n);
        ans -= get_count(r - l - 1);
        for (ll i = 1; i < a.size(); i++)
        {
            r = a[i] + t.size() - 1;
            l = a[i - 1] + 1;
            n = r - l;
            ans += get_count(n);
            l = a[i];
            ans -= get_count(r - l - 1);
        }
        n = s.size() - (a[a.size() - 1] + 1);
        ans += get_count(n);
    }
    else {
        ans += get_count(s.size());
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