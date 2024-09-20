#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int request(string s) {
    cout << "? " << s << endl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void solve() {
    ll n; cin >> n;
    string s = "";
    if (request("0")) s += "0";
    else s += "1";
    bool right = true;
    while(s.length() < n) {
        if (right) {
            if (request(s + "0")) {
                s += "0";
            }
            else if (request(s + "1")) {
                s += "1";
            }
            else {
                right = false;
            }
        }
        else {
            if (request("0" + s)) {
                s = "0" + s;
            } else s = "1" + s;
        }
    }
    cout << "! " << s << endl;
    return;
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