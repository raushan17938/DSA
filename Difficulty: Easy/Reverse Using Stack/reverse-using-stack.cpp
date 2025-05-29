class Solution {
  public:
    string reverse(const string& S) {
        stack<char> st;
        

        for (char ch : S) {
            st.push(ch);
        }

        
        string reversed = "";
        while (!st.empty()) {
            reversed += st.top();
            st.pop();
        }

        return reversed;
    }
};