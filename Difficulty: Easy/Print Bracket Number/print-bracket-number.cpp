// User function template for C++
class Solution {
  public:
    vector<int> bracketNumbers(string str) {
        vector<int> result;
        stack<int> st;
        int count = 1;

        for (char ch : str) {
            if (ch == '(') {
                st.push(count);
                result.push_back(count);
                count++;
            } else if (ch == ')') {
                if (!st.empty()) {
                    result.push_back(st.top());
                    st.pop();
                }
            }
        }

        return result;
    }
};
