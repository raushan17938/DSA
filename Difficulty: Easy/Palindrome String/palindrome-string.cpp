class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        int st = 0;
        int end = s.size() - 1;
        int is_palindrome = 1;
        while(st<end){
            if(s[st]!=s[end]){
                is_palindrome = 0;
                break;
            }
            st++;
            end--;
        }
        
        return is_palindrome;
        
    }
};