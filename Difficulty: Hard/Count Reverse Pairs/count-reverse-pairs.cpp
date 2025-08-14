class Solution {
public:
    int countRevPairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
private:
    int mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        return mergeSort(arr, l, m) + mergeSort(arr, m + 1, r) + merge(arr, l, m, r);
    }
    int merge(vector<int>& arr, int l, int m, int r) {
        int cnt = 0, j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && arr[i] > 2LL * arr[j]) j++;
            cnt += j - m - 1;
        }
        vector<int> temp(r - l + 1);
        int i = l, k = 0;
        j = m + 1;
        while (i <= m && j <= r) temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        for (i = l; i <= r; i++) arr[i] = temp[i - l];
        return cnt;
    }
};