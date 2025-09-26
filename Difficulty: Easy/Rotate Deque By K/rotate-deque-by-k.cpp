class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) {
            for (int i = 0; i < k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        } else {
            for (int i = 0; i < k; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
};