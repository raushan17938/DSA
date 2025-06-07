class Solution {
  public:
    // Function to calculate sum of all numbers present in a string.
    int findSum(string& s) {
        int sum = 0;
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                
                num = num * 10 + (ch - '0');
            } else {
               
                sum += num;
                num = 0;
            }
        }

        
        sum += num;

        return sum;
    }
};
