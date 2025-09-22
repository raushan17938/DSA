class Solution {
public:
    vector<int> maxOfMins(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n), mx(n + 1);
        stack<int> st;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || a[st.top()] >= a[i])) {
                int mid = st.top(); st.pop();
                int w = i - (st.empty() ? -1 : st.top()) - 1;
                mx[w] = max(mx[w], a[mid]);
            }
            st.push(i);
        }
        
        for (int i = 1; i <= n; i++) ans[i-1] = mx[i];
        for (int i = n-2; i >= 0; i--) ans[i] = max(ans[i], ans[i+1]);
        return ans;
    }
};