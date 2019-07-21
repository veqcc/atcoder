#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> A(n);
    int mx = 0, snd_mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] > mx) {
            snd_mx = mx;
            mx = A[i];
        } else if (A[i] > snd_mx) {
            snd_mx = A[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (A[i] == mx) {
            cout << snd_mx << "\n";
        } else {
            cout << mx << '\n';
        }
    }

    return 0;
}