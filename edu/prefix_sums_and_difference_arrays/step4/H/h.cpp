#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> da(n, 0);
    ll q; cin >> q;
    while (q--)
    {
        ll k, x; cin >> k >> x;
        da[n - k] += x;
    }
    for (ll i = 1; i < n; i++)
    {
        da[i] += da[i - 1];
    }

    for (ll i = 0; i < n; i++)
    {
        a[i] += da[i];
        cout << a[i] << " ";
    }
    cout << "\n";


    return 0;
}