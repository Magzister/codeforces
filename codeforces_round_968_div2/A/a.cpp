#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        string s; cin >> s;
        if (s[0] == s[n - 1])
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
    

    return 0;
}