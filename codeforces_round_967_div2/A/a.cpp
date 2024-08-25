#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


typedef long long ll;


void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<ll, ll> count;
    for (ll i = 0; i < n; i++)
    {
        if (count.count(a[i]))
        {
            count[a[i]] += 1;
        }
        else
        {
            count[a[i]] = 1;
        }
    }

    ll max_count = 0;
    for (auto iter = count.begin(); iter != count.end(); iter++)
    {
        max_count = max(iter->second, max_count);
    }

    cout << n - max_count << endl;
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