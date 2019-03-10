class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int n = A.size();
        sort(A.begin(), A.end());

        int sm = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] < 0 && K > 0) {
                sm -= A[i];
                K--;
            } else {
                sm += A[i];
            }
            A[i] = abs(A[i]);
        }

        sort(A.begin(), A.end());
        if (K % 2 == 1) sm -= 2 * A[0];

        return sm;
    }
};