// User function template for C++

class Solution {
  public:

    bool checkEqual(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size()) return false;

        unordered_map<int, int> freqA, freqB;

  
        for (int num : a) {
            freqA[num]++;
        }


        for (int num : b) {
            freqB[num]++;
        }


        return freqA == freqB;
    }
};
