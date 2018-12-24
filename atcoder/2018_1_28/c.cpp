#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a1[n];
    int a2[n];
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a2[i];
    }

    for (int i = 1; i < n; i++) {
        a1[i] += a1[i-1];
    }

    for (int i = n-2; i >= 0; i--) {
        a2[i] += a2[i+1];
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, a1[i]+a2[i]);
    }

    cout << maxi << endl;
    return 0;
}