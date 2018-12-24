#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    int count4 = 0;
    int count2 = 0;
    int count1 = 0;
    int in;
    for (int i = 0; i < n; i++) {
        cin >> in;
        if (in % 4 == 0) {
            count4++;
        } else if (in % 2 == 0) {
            count2++;
        } else {
            count1++;
        }
    }

    string ans = "No";
    if (count2 == 0) {
        if (count4 >= count1 - 1) {
            ans = "Yes";
        }
    } else {
        if (count4 >= count1) {
            ans = "Yes";
        }
    }

    cout << ans << endl;
    return 0;
}