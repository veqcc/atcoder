#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int flag = true;
    int count = 0;
    while (flag) {
        flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i+1]) {
                swap(v[i], v[i+1]);
                flag = true;
                count++;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        if (j) cout << " ";
        cout << v[j];
    }
    cout << "\n";

    cout << count << "\n";
    return 0;
}