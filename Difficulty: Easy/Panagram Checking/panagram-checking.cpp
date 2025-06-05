// User function template for C++

class Solution {
  public:
  
    bool checkPangram(string& s) {
        
        bool seen[26] = {false};

        for (char c : s) {
            if (isalpha(c)) { 
                c = tolower(c);
                seen[c - 'a'] = true; 
            }
        }

   
        for (int i = 0; i < 26; i++) {
            if (!seen[i]) return false;
        }

        return true;
    }
};
