#include <iostream>
#include <vector>


typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }

    vector<ll> da(n);
    for (ll i = 0; i < n; i++)
    {
        da[i] = a[i + 1] - a[i];
    }

    ll q; cin >> q;
    while (q--)
    {
        ll l, r, d; cin >> l >> r >> d;
        l--;
        da[l] += d;
        if (r <= n - 1)
        {
            da[r] -= d;
        }
    }

    vector<ll> ans(n);
    ans[0] = a[0] + da[0];
    for (ll i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] + da[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}