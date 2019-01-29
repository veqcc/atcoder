#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    int length[q];
    string S[q];
    for (int i = 0; i < q; i++) {
        cin >> length[i] >> S[i];
    }

    for (int i = 0; i < q; i++) {
        if (length[i] >= 3 || S[i][0] < S[i][1]) {
            cout << "YES\n2\n" << S[i][0] << " ";
            for (int j = 1; j < length[i]; j++) {
                cout << S[i][j];
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}