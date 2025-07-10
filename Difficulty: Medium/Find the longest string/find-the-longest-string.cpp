class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_map<string, vector<string>> adj;
        unordered_set<string> wordSet(words.begin(), words.end());
        
        for (string& w : words) {
            if (w.length() > 1) {
                string prefix = w.substr(0, w.length() - 1);
                if (wordSet.count(prefix)) adj[prefix].push_back(w);
            }
        }
        
        string result = "";
        for (string& w : words) {
            if (w.length() == 1) {
                string temp = dfs(w, adj);
                if (temp.length() > result.length()) result = temp;
            }
        }
        return result;
    }
    
private:
    string dfs(string word, unordered_map<string, vector<string>>& adj) {
        string longest = word;
        for (string& next : adj[word]) {
            string candidate = dfs(next, adj);
            if (candidate.length() > longest.length()) longest = candidate;
        }
        return longest;
    }
};