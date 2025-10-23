class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<long long, int>> maxHeap;

        for (int i = 0; i < points.size(); ++i) {
            long long x = points[i][0];
            long long y = points[i][1];
            
            long long dist = (x * x) + (y * y);
            
            maxHeap.push({dist, i});
            
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second;
            result.push_back(points[index]);
            maxHeap.pop();
        }
        
        return result;
    }
};