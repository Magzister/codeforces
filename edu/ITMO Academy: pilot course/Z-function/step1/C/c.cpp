#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

void solve() {
    string s; cin >> s;
    string p; cin >> p;
    vector<int> a;
    int ans = 0;
    int ind = s.size() - p.size();
    for (int i = 0; i <= ind; i++)
    {

        bool match = true;
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] == '?') {
                continue;
            }
            if (s[i + j] != p[j])
            {
                match = false;
                break;
            }
        }
        if (match) {
            ans++;
            a.push_back(i);
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
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