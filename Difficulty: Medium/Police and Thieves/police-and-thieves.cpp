class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), i = 0, j = 0, c = 0;
        while (i < n && j < n) {
            while (i < n && arr[i] != 'P') i++;
            while (j < n && arr[j] != 'T') j++;
            if (i < n && j < n && abs(i - j) <= k) i++, j++, c++;
            else if (j < i) j++;
            else i++;
        }
        return c;
    }
};