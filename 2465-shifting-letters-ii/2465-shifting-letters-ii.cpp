class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
         int n = s.size();
        vector<int> shift_effect(n + 1, 0); 

        
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) { 
                shift_effect[start] += 1;
                if (end + 1 < n) shift_effect[end + 1] -= 1;
            } else { 
                shift_effect[start] -= 1;
                if (end + 1 < n) shift_effect[end + 1] += 1;
            }
        }

        
        int current_shift = 0;
        for (int i = 0; i < n; ++i) {
            current_shift += shift_effect[i];
          
            int shift_value = (current_shift % 26 + 26) % 26; 
            s[i] = 'a' + (s[i] - 'a' + shift_value) % 26;
        }

        return s;
    }
};