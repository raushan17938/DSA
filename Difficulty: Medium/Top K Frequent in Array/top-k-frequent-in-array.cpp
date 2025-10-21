class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }
        
        priority_queue<pair<int, int>> maxHeap;
        
        for (auto& pair : freqMap) {
            maxHeap.push({pair.second, pair.first});
        }
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop(); 
        }
        
        return result;
    }
};