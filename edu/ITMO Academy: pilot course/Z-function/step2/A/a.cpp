#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    vector<ll> z(s.size(), 0);
    for (ll i = 1; i < s.size(); i++)
    {
        while (z[i] + i < s.size() && s[z[i] + i] == s[z[i]]) z[i]++;
    }
    for (ll i = 0; i < z.size(); i++)
    {
        cout << z[i] << " ";
    }
    cout << "\n";

    return 0;
}