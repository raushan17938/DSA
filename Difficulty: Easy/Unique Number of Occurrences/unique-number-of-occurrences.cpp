

class Solution {
  public:
    bool isFrequencyUnique(int n, int arr[]) {
        std::unordered_map<int, int> freq;

        
        for (int i = 0; i < n; ++i) {
            freq[arr[i]]++;
        }

        std::unordered_set<int> freqSet;

      
        for (auto &entry : freq) {
            if (freqSet.find(entry.second) != freqSet.end()) {
            
                return false;
            }
            freqSet.insert(entry.second);
        }

        return true;
    }
};
