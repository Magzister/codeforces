#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        cout << a[n / 2] << "\n";
    }
    

    return 0;
}