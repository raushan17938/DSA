class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
         int m = mat.size();    
        int n = mat[0].size(); 

        
        unordered_map<int, pair<int, int>> position;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                position[mat[i][j]] = {i, j};
            }
        }

    
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        
        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            auto [r, c] = position[num];

        
            rowCount[r]++;
            colCount[c]++;

            
            if (rowCount[r] == n || colCount[c] == m) {
                return i;
            }
        }

        
        return -1;
    }
};