#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

void solve() {
    ll n; cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    string s; cin >> s;

    vector<ll> res(n, 0);
    vector<ll> visited(n, 0);
    for (ll i = 0; i < n; i++)
    {
        ll acc = 0;
        if (visited[i]) continue;
        vector<ll> loop;
        ll cur_el = i;
        while (true)
        {
            if (visited[cur_el]) {
                break;
            }
            visited[cur_el] = 1;
            if (s[cur_el] == '0') {
                acc++;
            }
            loop.push_back(cur_el);
            cur_el = p[cur_el] - 1;
        }
        for (ll i = 0; i < loop.size(); i++)
        {
            res[loop[i]] = acc;
        }

    }
    for (ll i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
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