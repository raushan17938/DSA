class Solution {
  public:
    // a, b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> result;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            // Skip duplicates in a[]
            while (i > 0 && i < n && a[i] == a[i - 1]) i++;
            
            while (j > 0 && j < m && b[j] == b[j - 1]) j++;
            
            if (i >= n || j >= m) break;

            if (a[i] < b[j]) {
                result.push_back(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                result.push_back(b[j]);
                j++;
            } else {
                result.push_back(a[i]);
                i++;
                j++;
            }
        }

        
        while (i < n) {
            if (i == 0 || a[i] != a[i - 1])
                result.push_back(a[i]);
            i++;
        }

    
        while (j < m) {
            if (j == 0 || b[j] != b[j - 1])
                result.push_back(b[j]);
            j++;
        }

        return result;
    }
};
