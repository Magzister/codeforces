#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    vector<ll> z(67108863, 0);
    ll acc = 1;
    for (ll i = 2; i <= 26; i++)
    {
        acc *= 2;
        z[acc] = acc - 1;
        for (ll j = 1; j <= acc - 2; j++)
        {
            z[acc + j] = z[j];
        }

    }

    while (t--)
    {
        ll k, j; cin >> k >> j;
        cout << z[j] << "\n";
    }

    return 0;
}