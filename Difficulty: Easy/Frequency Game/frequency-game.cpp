

class Solution {
  public:
    int LargButMinFreq(int arr[], int n) {
        std::map<int, int> freq;

  
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        int minFreq = INT_MAX;
        int result = -1;

      
        for (auto& it : freq) {
            int element = it.first;
            int count = it.second;

            if (count < minFreq) {
                minFreq = count;
                result = element;
            } else if (count == minFreq && element > result) {
                result = element;
            }
        }

        return result;
    }
};
