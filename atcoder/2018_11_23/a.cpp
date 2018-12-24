#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 4;
    }

    cout << ans << endl;
    return 0;
}