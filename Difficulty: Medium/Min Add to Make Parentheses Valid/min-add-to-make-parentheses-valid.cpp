class Solution {
public:
    int minParentheses(string& s) {
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(') open++;
            else if (c == ')') open > 0 ? open-- : close++;
        }
        return open + close;
    }
};