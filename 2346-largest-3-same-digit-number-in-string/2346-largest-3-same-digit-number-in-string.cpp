class Solution {
public:
    string largestGoodInteger(string num) {
        for (int i = 9; i >= 0; --i) {
            string target(3, i + '0');
            if (num.find(target) != string::npos) {
                return target;
            }
        }
        return "";
    }
};