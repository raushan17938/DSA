class Solution {
public:
    int climbStairs(int n) {
      int prev2 = 0;
        int prev1 = 1;
      
        // Calculate the n-th Fibonacci number iteratively
        // The number of ways to climb n stairs equals the (n+1)-th Fibonacci number
        for (int i = 0; i < n; ++i) {
            // Calculate current Fibonacci number: F(i) = F(i-1) + F(i-2)
            int current = prev2 + prev1;
          
            // Shift the window: move forward by one position
            prev2 = prev1;  // F(i-2) becomes F(i-1)
            prev1 = current;  // F(i-1) becomes F(i)
        }
      
        // Return the result which represents the number of distinct ways
        return prev1;
    }
};