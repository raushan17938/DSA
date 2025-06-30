class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> xorFreq;
        long count = 0;
        int xorSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            xorSum ^= arr[i];


            if (xorSum == k)
                count++;

         
            int required = xorSum ^ k;
            if (xorFreq.find(required) != xorFreq.end()) {
                count += xorFreq[required];
            }

           
            xorFreq[xorSum]++;
        }

        return count;
    }
};
