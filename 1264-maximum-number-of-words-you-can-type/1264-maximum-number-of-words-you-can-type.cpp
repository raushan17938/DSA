class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
       
        bool isBroken[26] = {false};
      
        for (char letter : brokenLetters) {
            isBroken[letter - 'a'] = true;
        }
      
        int typeableWordCount = 0;
        vector<string> words = split(text, ' ');
      
        for (const string& word : words) {
            bool canTypeWord = true;
          
            // Check if any character in the word is broken
            for (char character : word) {
                if (isBroken[character - 'a']) {
                    canTypeWord = false;
                    break;
                }
            }
          
            // Increment count if word can be typed
            if (canTypeWord) {
                typeableWordCount++;
            }
        }
      
        return typeableWordCount;
    }

private:
    vector<string> split(const string& inputString, char delimiter) {
        vector<string> result;
        string currentWord;
      
        for (char currentChar : inputString) {
            if (currentChar == delimiter) {
                result.push_back(currentWord);
                currentWord.clear();
            } else {
                currentWord.push_back(currentChar);
            }
        }
      
        result.push_back(currentWord);
      
        return result;
    }
};
