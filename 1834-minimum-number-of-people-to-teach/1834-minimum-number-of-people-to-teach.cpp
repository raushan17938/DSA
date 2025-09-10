class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
       
        unordered_set<int> usersNeedingHelp;
      
        for (auto& friendship : friendships) {
            int user1 = friendship[0];
            int user2 = friendship[1];
          
            if (!haveCommonLanguage(user1, user2, languages)) {
                usersNeedingHelp.insert(user1);
                usersNeedingHelp.insert(user2);
            }
        }
      
        if (usersNeedingHelp.empty()) {
            return 0;
        }
      
        vector<int> languageCount(n + 1, 0);  
      
        for (int userId : usersNeedingHelp) {
            for (int& languageId : languages[userId - 1]) {  
                ++languageCount[languageId];
            }
        }
      
        int maxUsersKnowingLanguage = *max_element(languageCount.begin(), languageCount.end());
      
        return usersNeedingHelp.size() - maxUsersKnowingLanguage;
    }

private:
    bool haveCommonLanguage(int user1, int user2, vector<vector<int>>& languages) {
        for (int language1 : languages[user1 - 1]) {  
            for (int language2 : languages[user2 - 1]) {  
                if (language1 == language2) {
                    return true;  
                }
            }
        }
        return false; 
    }
};
