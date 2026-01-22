class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        stack<int> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] < arr[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans += (long long)arr[mid] * (mid - left) * (i - mid);
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans -= (long long)arr[mid] * (mid - left) * (i - mid);
            }
            st.push(i);
        }
        return (int)ans;
    }
};