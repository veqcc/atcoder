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

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        for (int i = 1; K > 0;i++) {
            int ad = K % 10;
            K /= 10;
            int pos = A.size() - i;

            while (true) {
                if (pos < 0) {
                    pos = 0;
                    auto it = A.begin();
                    it = A.insert(it, 0);
                }

                int tmp = A[pos] + ad;
                if (tmp < 10) {
                    A[pos] = tmp;
                    break;
                } else {
                    A[pos] = tmp - 10;
                    pos--;
                    ad = 1;
                }
            }
        }

        return A;
    }
};
