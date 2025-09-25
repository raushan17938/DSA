class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int x = i + 1; x; x /= 2) s = char('0' + x % 2) + s;
            res[i] = s;
        }
        return res;
    }
};
