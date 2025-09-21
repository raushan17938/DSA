class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            stack<int> st;
            for (int j = 0; j <= m; j++) {
                int cur = j == m ? 0 : h[j];
                while (!st.empty() && h[st.top()] > cur) {
                    int tp = st.top(); st.pop();
                    int w = st.empty() ? j : j - st.top() - 1;
                    res = max(res, h[tp] * w);
                }
                st.push(j);
            }
        }
        return res;
    }
};