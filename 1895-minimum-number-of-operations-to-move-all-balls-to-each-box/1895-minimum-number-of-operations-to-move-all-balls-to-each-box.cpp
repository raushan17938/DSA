class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        
        int count = 0; 
        int operations = 0; 
        for (int i = 0; i < n; ++i) {
            answer[i] += operations;
            if (boxes[i] == '1') {
                count++;
            }
            operations += count;
        }

      
        count = 0; 
        operations = 0; 
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += operations;
            if (boxes[i] == '1') {
                count++;
            }
            operations += count;
        }

        return answer;
    }
};