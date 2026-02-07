class Solution {
  public:
    long long maxSum(vector<int> &arr) {
        long long n = arr.size();
        long long sum = 0;
        long long curr_sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            curr_sum += (long long)i * arr[i];
        }
        
        long long max_sum = curr_sum;
        
        for(int i = 0; i < n - 1; i++) {
            curr_sum = curr_sum - sum + (long long)n * arr[i];
            if(curr_sum > max_sum) {
                max_sum = curr_sum;
            }
        }
        
        return max_sum;
    }
};