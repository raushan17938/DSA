class Solution {
public:
    string maxSubseq(string &s, int k) {
        deque<char> dq;
        int toRemove = k;
        for (char c : s) {
            while (!dq.empty() && toRemove && dq.back() < c) {
                dq.pop_back();
                toRemove--;
            }
            dq.push_back(c);
        }
        string res;
        for (int i = 0; i < s.length() - k; ++i) res += dq[i];
        return res;
    }
};