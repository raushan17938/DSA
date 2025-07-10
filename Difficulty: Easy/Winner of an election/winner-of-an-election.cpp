class Solution {
  public:

    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n) {
        unordered_map<string, int> voteCount;

     
        for (int i = 0; i < n; ++i) {
            voteCount[arr[i]]++;
        }

        string winnerName = "";
        int maxVotes = 0;

        for (auto& entry : voteCount) {
            string name = entry.first;
            int votes = entry.second;

           
            if (votes > maxVotes || (votes == maxVotes && name < winnerName)) {
                winnerName = name;
                maxVotes = votes;
            }
        }

    
        return {winnerName, to_string(maxVotes)};
    }
};