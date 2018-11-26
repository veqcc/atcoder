#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 3) {
        cout << 2 << " " << 5 << " " << 63 << endl;
    } else if (N == 4) {
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
    } else if (N == 5) {
        cout << 2 << " " << 5 << " " << 20 << " " << 30 << " " << 63 << endl;
    } else {
        ll sum = 0;
        ll current = 2;
        vector <ll> vec;
        for (int i = 0; i < N; i++) {
            if (current % 6 == 1 || current % 6 == 5) {
                vec.push_back(current + 1);
                sum += (ll)(current + 1);
                current += 2;
            } else {
                vec.push_back(current);
                sum += (ll)(current);
                current++;
            }
        }

        if (sum % 6 == 2 || sum % 6 == 3) {
            vec.at((sum % 6) + 2) = -1;
            while (true) {
                if (current % 6 == 0) {
                    vec.push_back(current);
                    break;
                } else {
                    current++;
                }
            }
        } else if (sum % 6 == 5) {
            vec.at(5) = -1;
            while (true) {
                if (current % 6 == 4) {
                    vec.push_back(current);
                    break;
                } else {
                    current++;
                }
            }
        }

        for (int i = 0; i < vec.size(); i++) {
            if (vec.at(i) != -1) {
                cout << vec.at(i) << " ";
            }
        }
    }

    return 0;
}