#include <iostream>
#include <string>
#include <algorithm>

typedef long long ll;

using namespace std;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    ll sqrt_n = 0;
    for (ll i = 1; i <= n / 2; i++)
    {
        if (i * i == n)
        {
            sqrt_n = i;
            break;
        }
    }
    if (!sqrt_n)
    {
        cout << "No" << "\n";
        return;
    }
    else
    {
        for (ll i = 0; i < sqrt_n; i++)
        {
            if (s[i] == '0')
            {
                cout << "No" << "\n";
                return;
            }
        }
        for (ll i = n - sqrt_n; i < n; i++)
        {
            if (s[i] == '0')
            {
                cout << "No" << "\n";
                return;
            }
        }
        for (ll i = 0; i < sqrt_n - 2; i++)
        {
            if (s[(i + 1) * sqrt_n] != '1')
            {
                cout << "No" << "\n";
                return;
            }
            if (s[((i + 1) * sqrt_n) - 1] != '1')
            {
                cout << "No" << "\n";
                return;
            }
            for (ll j = ((i + 1) * sqrt_n) + 1; j < (((i + 1) * sqrt_n) - 1) + sqrt_n; j++)
            {
                if (s[j] != '0')
                {
                    cout << "No" << "\n";
                    return;
                }
            }
        }
        cout << "Yes" << "\n";
        return;
    }
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