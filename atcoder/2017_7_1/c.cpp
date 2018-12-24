#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector <int> b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if ((n+i) % 2 == 0) {
            b.push_back(a);
        } else {
            b.insert(b.begin(), a);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b.at(i) << " ";
    }

    return 0;
}