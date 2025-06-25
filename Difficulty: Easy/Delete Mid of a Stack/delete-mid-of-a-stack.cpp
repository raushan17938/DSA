class Solution {
  public:
    // Helper function for recursive deletion
    void deleteMidUtil(stack<int>& s, int curr, int size) {
     
        if (curr == size / 2) {
            s.pop(); 
            return;
        }

        int temp = s.top();
        s.pop();


        deleteMidUtil(s, curr + 1, size);


        s.push(temp);
    }


    void deleteMid(stack<int>& s) {
        int size = s.size();
        deleteMidUtil(s, 0, size);
    }
};
