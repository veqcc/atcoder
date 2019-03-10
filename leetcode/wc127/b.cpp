class Solution {
public:
    int clumsy(int N) {
        int ans;

        if (N > 4) {
            ans = N * (N - 1) / (N - 2) + N - 3;
            N -= 4;
            for (; N > 4; N -= 4) {
                ans = ans - N * (N - 1) / (N - 2) + N - 3;
            }

            if (N == 4) ans -= 5;
            if (N == 3) ans -= 6;
            if (N == 2) ans -= 2;
            if (N == 1) ans -= 1;
        } else {
            if (N == 4) ans = 7;
            if (N == 3) ans = 6;
            if (N == 2) ans = 2;
            if (N == 1) ans = 1;
        }

        return ans;
    }
};