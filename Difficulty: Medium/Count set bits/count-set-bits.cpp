class Solution {
  public:
    int countSetBits(int n) {
        if (n <= 0) return 0;
        
    
        int x = 0;
        int temp = n;
        while (temp > 1) {
            temp >>= 1;
            x++;
        }
        
      
        int bitsInGroups = (x == 0) ? 0 : (x * (1 << (x - 1)));
        
        int msbBits = n - (1 << x) + 1;
        
        int remainingBits = countSetBits(n - (1 << x));
        
        return bitsInGroups + msbBits + remainingBits;
    }
};