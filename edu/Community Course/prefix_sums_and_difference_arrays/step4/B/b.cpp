#include <iostream>
#include <vector>

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

    vector<ll> da1(n, 0);
    vector<ll> da2(n, 0);

    for (ll i = 1; i < n; i++)
    {
        da1[i] = a[i] - a[i - 1];
    }
    for (ll i = 1; i < n; i++)
    {
        da2[i] = da1[i] - da1[i - 1];
    }

    ll q; cin >> q;
    while (q--)
    {
        ll l, r, d;
        cin >> l >> r >> d;
        l--;
        
        da2[l] += d;
        if (r < n)
        {
            da2[r] -= (r - l + 1) * d;
        }
        if (r + 1 < n)
        {
            da2[r + 1] += (r - l) * d;
        }
    }

    da1[0] += da2[0];
    for (ll i = 1; i < n; i++)
    {
        da1[i] = da1[i - 1] + da2[i];
    }
    a[0] += da1[0];
    for (ll i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + da1[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}