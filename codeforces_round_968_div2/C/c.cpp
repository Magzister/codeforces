#include <iostream>
#include <vector>
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
        for (ll i = 0; i < n - 1; i += 2)
        {
            swap(s[i], s[i + 1]);
        }
        
        cout << s << "\n";
    }
    

    return 0;
}