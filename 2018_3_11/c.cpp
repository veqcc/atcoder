#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (N == 1 && M == 1) {
        cout << 1 << endl;
    } else if (N == 1) {
        cout << M-2 << endl;
    } else if (M == 1) {
        cout << N-2 << endl;
    } else {
        cout << (N-2) * (M-2) << endl;
    }
    return 0;
}