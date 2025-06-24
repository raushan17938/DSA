class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> freq;

      
        for (int num : a) {
            freq[num]++;
        }

       
        for (int num : b) {
            if (freq[num] > 0) {
                freq[num]--;
            } else {
                return false; 
            }
        }

        return true;
    }
};