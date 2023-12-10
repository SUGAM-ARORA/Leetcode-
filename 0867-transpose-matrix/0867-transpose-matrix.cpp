class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size(), 0));

        for (size_t r = 0; r < matrix.size(); r++) {
            for (size_t c = 0; c < matrix[0].size(); c++) {
                res[c][r] = matrix[r][c];
            }
        }

        return res;        
    }
};