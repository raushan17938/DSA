class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k);
        int idx = 0;
        for (int i = k; i < arr.size(); i++) {
            pq.push(arr[i]);
            arr[idx++] = pq.top();
            pq.pop();
        }
        while (!pq.empty()) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};