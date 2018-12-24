#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n=0, s=0, e=0, w=0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'N') n=1;
        if (S[i] == 'S') s=1;
        if (S[i] == 'E') e=1;
        if (S[i] == 'W') w=1;
    }

    if (n == s && e == w) cout << "Yes";
    else cout << "No";

    return 0;
}