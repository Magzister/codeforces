#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

    ll l = 0, r = 0;
    ll best_l = 0, best_r = 0;
    ll curr_sum = 0;
    ll best_sum = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] <= curr_sum + a[i])
        {
            r = i;
            curr_sum += a[i];
        }
        else
        {
            l = i;
            r = i;
            curr_sum = a[i];
        }

        if (best_sum < curr_sum)
        {
            best_sum = curr_sum;
            best_l = l;
            best_r = r;
        }
    }

    cout << best_l + 1 << " " << best_r + 1 << " " << best_sum << "\n";

    return 0;
}