#include <iostream>
#include <vector>


typedef long long ll;


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n1, n2, n3, n4, n5; cin >> n1 >> n2 >> n3 >> n4 >> n5;
    vector<vector<vector<vector<vector<ll>>>>> a(
        n1, vector<vector<vector<vector<ll>>>>(
            n2, vector<vector<vector<ll>>>(
                n3, vector<vector<ll>>(
                    n4, vector<ll>(n5)
                )
            )
        )
    );
    for (ll i = 0; i < n1; i++)
    {
        for (ll j = 0; j < n2; j++)
        {
            for (ll k = 0; k < n3; k++)
            {
                for (ll x = 0; x < n4; x++)
                {
                    for (ll y = 0; y < n5; y++)
                    {
                        cin >> a[i][j][k][x][y];
                    }
                }
            }
        }
    }

    vector<vector<vector<vector<vector<ll>>>>> ps(
        n1 + 1, vector<vector<vector<vector<ll>>>>(
            n2 + 1, vector<vector<vector<ll>>>(
                n3 + 1, vector<vector<ll>>(
                    n4 + 1, vector<ll>(n5 + 1, 0)
                )
            )
        )
    );

    for (ll i = 0; i < n1; i++)
    {
        for (ll j = 0; j < n2; j++)
        {
            for (ll k = 0; k < n3; k++)
            {
                for (ll x = 0; x < n4; x++)
                {
                    for (ll y = 0; y < n5; y++)
                    {
                        ps[i + 1][j + 1][k + 1][x + 1][y + 1] =
                        ps[i][j + 1][k + 1][x + 1][y + 1] +
                        ps[i + 1][j][k + 1][x + 1][y + 1] +
                        ps[i + 1][j + 1][k][x + 1][y + 1] +
                        ps[i + 1][j + 1][k + 1][x][y + 1] +
                        ps[i + 1][j + 1][k + 1][x + 1][y] -
                        ps[i + 1][j + 1][k + 1][x][y] -
                        ps[i][j + 1][k + 1][x + 1][y] -
                        ps[i][j][k + 1][x + 1][y + 1] -
                        ps[i + 1][j + 1][k][x + 1][y] -
                        ps[i + 1][j + 1][k][x][y + 1] -
                        ps[i + 1][j][k + 1][x + 1][y] -
                        ps[i + 1][j][k + 1][x][y + 1] -
                        ps[i + 1][j][k][x + 1][y + 1] -
                        ps[i][j + 1][k][x + 1][y + 1] -
                        ps[i][j + 1][k + 1][x][y + 1] +
                        ps[i + 1][j + 1][k][x][y] +
                        ps[i + 1][j][k + 1][x][y] +
                        ps[i + 1][j][k][x + 1][y] +
                        ps[i + 1][j][k][x][y + 1] +
                        ps[i][j + 1][k + 1][x][y] +
                        ps[i][j + 1][k][x + 1][y] +
                        ps[i][j + 1][k][x][y + 1] +
                        ps[i][j][k + 1][x + 1][y] +
                        ps[i][j][k + 1][x][y + 1] +
                        ps[i][j][k][x + 1][y + 1] -
                        ps[i + 1][j][k][x][y] -
                        ps[i][j + 1][k][x][y] -
                        ps[i][j][k + 1][x][y] -
                        ps[i][j][k][x + 1][y] -
                        ps[i][j][k][x][y + 1] +
                        ps[i][j][k][x][y] +
                        a[i][j][k][x][y];
                    }
                }
            }
        }
    }

    ll q; cin >> q;
    while (q--)
    {
        ll l1, l2, l3, l4, l5, r1, r2, r3, r4, r5;
        cin >> l1 >> l2 >> l3 >> l4 >> l5 >> r1 >> r2 >> r3 >> r4 >> r5;
        l1--;
        l2--;
        l3--;
        l4--;
        l5--;
        ll ans = ps[r1][r2][r3][r4][r5] - ps[l1][l2][l3][l4][l5] +
        ps[l1][l2][r3][r4][r5] +
        ps[l1][r2][l3][r4][r5] +
        ps[l1][r2][r3][l4][r5] +
        ps[l1][r2][r3][r4][l5] +
        ps[r1][l2][l3][r4][r5] +
        ps[r1][l2][r3][l4][r5] +
        ps[r1][l2][r3][r4][l5] +
        ps[r1][r2][l3][l4][r5] +
        ps[r1][r2][l3][r4][l5] +
        ps[r1][r2][r3][l4][l5] +
        ps[l1][l2][l3][l4][r5] +
        ps[l1][l2][l3][r4][l5] +
        ps[l1][l2][r3][l4][l5] +
        ps[l1][r2][l3][l4][l5] +
        ps[r1][l2][l3][l4][l5] -
        ps[l1][r2][r3][r4][r5] -
        ps[r1][l2][r3][r4][r5] -
        ps[r1][r2][l3][r4][r5] -
        ps[r1][r2][r3][l4][r5] -
        ps[r1][r2][r3][r4][l5] -
        ps[l1][l2][l3][r4][r5] -
        ps[r1][l2][l3][l4][r5] -
        ps[r1][r2][l3][l4][l5] -
        ps[l1][l2][r3][l4][r5] -
        ps[l1][l2][r3][r4][l5] -
        ps[l1][r2][l3][l4][r5] -
        ps[l1][r2][r3][l4][l5] -
        ps[l1][r2][l3][r4][l5] -
        ps[r1][l2][r3][l4][l5] - 
        ps[r1][l2][l3][r4][l5];

        cout << ans << endl;
    }
    
    return 0;
}