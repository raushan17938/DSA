class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (const auto& t : arr) {
            if (t.size() == 1 && strchr("+-*/^", t[0])) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (t[0] == '/') st.push((a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b);
                else st.push(t[0] == '+' ? a + b : t[0] == '-' ? a - b : 
                          t[0] == '*' ? a * b : pow(a, b));
            } else st.push(stoi(t));
        }
        return st.top();
    }
};