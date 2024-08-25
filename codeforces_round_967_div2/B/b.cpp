#include <iostream>


using namespace std;


typedef long long ll;


void solve() {
    ll n; cin >> n;

    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    
    if (n % 2 == 0)
    {
        cout << -1 << "\n";
        return;
    }

    for (ll i = n + 1 - n / 2; i < n + 1; i++)
    {
        cout << i << " ";
    }
    cout << 1 << " ";
    for (ll i = n - n / 2; i > 1; i--)
    {
        cout << i << " ";
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