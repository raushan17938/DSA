
class Solution {
  public:
    string oddEven(string s) {
        unordered_map<char, int> freq;

        
        for (char ch : s) {
            freq[ch]++;
        }

        int x = 0, y = 0;

      
        for (auto it : freq) {
            char ch = it.first;
            int count = it.second;

            
            int position = ch - 'a' + 1;

          
            if (position % 2 == 0 && count % 2 == 0) {
                x++;
            }
    
            else if (position % 2 == 1 && count % 2 == 1) {
                y++;
            }
        }

        int sum = x + y;

        return (sum % 2 == 0) ? "EVEN" : "ODD";
    }
};
