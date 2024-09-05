#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

using namespace std;

ui nextRand(ui &cur, ui a, ui b) {
    cur = cur * a + b;
    return cur >> 8;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ull n = (ull)1 << 24;
    ull mod = (ull)1 << 32;
    vector<ll> v(n, 0);
    ull m, q; cin >> m >> q;
    ui a, b; cin >> a >> b;
    ui cur = 0;

    for (ull i = 0; i < m; i++)
    {
        ll d = nextRand(cur, a, b);
        ll l = nextRand(cur, a, b);
        ll r = nextRand(cur, a, b);
        if (l > r) swap(l, r);
        r++;
        v[l] += d;
        v[l] %= mod;
        if (r < n) {
            v[r] -= d;
            v[r] %= mod;
        }
    }
    for (ull i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
        v[i] %= mod;
    }
    for (ull i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
        v[i] %= mod;
    }
    ull acc = 0;
    for (ull i = 0; i < q; i++)
    {
        ll l = nextRand(cur, a, b);
        ll r = nextRand(cur, a, b);
        if (l > r) swap(l, r);
        l--;
        acc += v[r];
        acc %= mod;
        if (l >= 0) {
            acc -= v[l];
            acc %= mod;
        }
    }
    cout << acc % mod << "\n";
    return 0;
}