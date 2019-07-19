#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (v[j] >= v[j-1]) break;
            swap(v[j], v[j-1]);
        }

        for (int j = 0; j < n; j++) {
            if (j) cout << " ";
            cout << v[j];
        }
        cout << "\n";
    }

    return 0;
}