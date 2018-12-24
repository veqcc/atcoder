#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int size = 100000;

int main() {
    int n, tmp;
    cin >> n;
    int X[size];
    fill(X, X+size, 0);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        tmp--;
        for (int j = max(tmp-1, 0); j < min(tmp+2, size); j++) {
            X[j]++;
        }
    }

    cout << *max_element(X, X+size) << endl;
    return 0;
}