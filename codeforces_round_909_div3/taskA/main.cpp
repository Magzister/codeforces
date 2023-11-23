#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n % 3 == 0) {
            cout << "Second" << endl;
        } else {
            cout << "First" << endl;
        }
    }
}
