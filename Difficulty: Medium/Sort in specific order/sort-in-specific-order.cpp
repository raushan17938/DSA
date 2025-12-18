class Solution {
  public:
    void sortIt(vector<int>& arr) {
        vector<int> odd;
        vector<int> even;
        
        for(int x : arr) {
            if(x % 2 != 0) {
                odd.push_back(x);
            } else {
                even.push_back(x);
            }
        }
        
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        
        int index = 0;
        
        for(int x : odd) {
            arr[index++] = x;
        }
        
        for(int x : even) {
            arr[index++] = x;
        }
    }
};