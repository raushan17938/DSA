class Solution {
public:
    bool doesAliceWin(string s) {
    
        const string VOWELS = "aeiou";
      
      
        for (char c : s) {
   
            if (VOWELS.find(c) != string::npos) {
                return true;
            }
        }
      
        return false;
    }
};
