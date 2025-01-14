class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
         int n = A.size();
        vector<int> prefixCommon(n, 0);
        unordered_set<int> seen;
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {
          
            if (seen.count(A[i])) {
                ++commonCount;
            } else {
                seen.insert(A[i]);
            }

            if (seen.count(B[i])) {
                ++commonCount;
            } else {
                seen.insert(B[i]);
            }

           
            prefixCommon[i] = commonCount;
        }

        return prefixCommon;
    }
};