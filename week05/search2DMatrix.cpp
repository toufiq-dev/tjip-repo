class Solution {
public:
    // TC: O(log(m * n)), m x n integer matrix
    // SC: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int L = 0;
        int R = (m * n) - 1;

        while(L <= R) {
            int M = L + (R - L) / 2;
            int x = M / n;
            int y = M % n;
            if(matrix[x][y] < target)
                L = M + 1;
            else if (matrix[x][y] > target) 
                R = M - 1;
            else 
                return true;
        }

        return false;
    }
};