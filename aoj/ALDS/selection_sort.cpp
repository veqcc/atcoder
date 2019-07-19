#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        int mn = v[i];
        int mn_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < mn) {
                mn = v[j];
                mn_idx = j;
            }
        }

        if (i != mn_idx) {
            count++;
            swap(v[i], v[mn_idx]);
        }
    }

    for (int j = 0; j < n; j++) {
        if (j) cout << " ";
        cout << v[j];
    }
    cout << "\n";

    cout << count << '\n';
    return 0;
}