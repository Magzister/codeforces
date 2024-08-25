#include <iostream>
#include <vector>
#include <system_error>


using namespace std;


int makeQuery(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    fflush(stdout);
    int response; cin >> response;
    return --response;
}


void solve() {
    int n; cin >> n;
    vector<int> in_tree(n, 0), stack;
    in_tree[0] = 1;
    for (int i = 0; i < n; i++)
    {
        stack.push_back(i);
    }
    vector<pair<int, int>> edges;

    while (!stack.empty())
    {
        int v = stack.back();
        stack.pop_back();

        if (in_tree[v])
        {
            continue;
        }

        int l = 0, r = v;
        while(true)
        {
            int q = makeQuery(l, r);
            if (q == l)
            {
                in_tree[r] = 1;
                edges.push_back({l, r});
                break;
            }
            if (in_tree[q])
            {
                l = q;
            }
            else
            {
                r = q;
            }
        }
        stack.push_back(v);
    }

    cout << "! ";
    for (int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].first + 1 << " " << edges[i].second + 1 << " ";
    }
    cout << endl;
}


int main() {
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}