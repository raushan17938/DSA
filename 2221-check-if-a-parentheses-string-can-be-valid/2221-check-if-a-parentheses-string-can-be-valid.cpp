class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; 

       
        int open = 0;  
        int flexible = 0;  
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') open++;
                else open--; 
            } else {
                flexible++; 
            }

            
            if (open + flexible < 0) return false;
        }

       
        int close = 0; 
        flexible = 0;  
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                if (s[i] == ')') close++;
                else close--; 
            } else {
                flexible++;
            }

    
            if (close + flexible < 0) return false;
        }

        return true;
    }
};