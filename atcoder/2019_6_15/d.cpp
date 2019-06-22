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
using namespace std;

int main() {
    int N;
    cin >> N;
    ll a[N];
    for (int i = 0; i < N; i++) cin >> a[i];

    ll abssum = 0;
    for (int i = 0; i < N; i++) abssum += abs(a[i]);

    //全部＋-----------------------------------------
    bool allplus = true;
    for (int i = 0; i < N; i++) {
        if (a[i] < 0) allplus = false;
    }
    if (allplus) {
        sort(a, a + N);
        cout << abssum - 2 * a[0] << endl;
        ll now = a[0];
        for (int i = 0; i < N - 2; i++) {
            cout << now << " " << a[i + 1] << endl;
            now = now - a[i + 1];
        }
        cout << a[N - 1] << " " << now << endl;
        return 0;
    }

    //全部---------------------------
    bool allmin = true;
    for (int i = 0; i < N; i++) {
        if (a[i] > 0) allmin = false;
    }
    if (allmin) {
        sort(a, a + N);
        reverse(a, a + N);
        cout << abssum + 2 * a[0] << endl;
        ll now = a[0];
        for (int i = 0; i < N - 1; i++) {
            cout << now << " " << a[i + 1] << endl;
            now = now - a[i + 1];
        }
        return 0;
    }

    //=====================================================

    queue <ll> sei;
    queue <ll> hu;

    for (int i = 0; i < N; i++) {
        if (a[i] >= 0) sei.push(a[i]);
        else if (a[i] < 0) hu.push(a[i]);
    }

    cout << abssum << endl;
    ll now;

    if (hu.size() == 1 && sei.size() == 1) {
        now = hu.front() - sei.front();
        cout << sei.front() << " " << hu.front() << endl;
        return 0;
    } else if (hu.size() == 1) {
        now = hu.front() - sei.front();
        cout << hu.front() << " " << sei.front() << endl;
    } else {
        now = sei.front() - hu.front();
        cout << sei.front() << " " << hu.front() << endl;
    }
    hu.pop();
    sei.pop();

    while (hu.size()) {
        //cout << "size" << hu.size() << endl;
        if (hu.size() == 1) {
            cout << hu.front() << " " << now << endl;
            now = hu.front() - now;
            hu.pop();
        } else {
            cout << now << " " << hu.front() << endl;
            now = now - hu.front();
            hu.pop();
        }
    }

    //cout << sei.size() << endl;

    while (sei.size()) {
        //cout << "size" << sei.size() << endl;
        if (sei.size() == 1) {
            cout << sei.front() << " " << now << endl;
            now = sei.front() - now;
            sei.pop();
        } else {
            cout << now << " " << sei.front() << endl;
            now = now - sei.front();
            sei.pop();
        }
    }

    return 0;
}
