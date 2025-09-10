class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size(), l = -1, r = -1, maxIdx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[maxIdx]) maxIdx = i;
            else if (s[i] < s[maxIdx]) l = i, r = maxIdx;
        }
        if (l != -1) swap(s[l], s[r]);
        return s;
    }
};