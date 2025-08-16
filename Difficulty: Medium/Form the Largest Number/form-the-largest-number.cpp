class Solution {
public:
    string findLargest(vector<int>& arr) {
        auto cmp = [](string a, string b) { return a + b < b + a; };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for (int x : arr) pq.push(to_string(x));
        string res = "";
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res[0] == '0' ? "0" : res;
    }
};