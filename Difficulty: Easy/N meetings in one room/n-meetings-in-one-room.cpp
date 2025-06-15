class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        
        vector<pair<int, int>> meetings(n);
        for (int i = 0; i < n; ++i) {
            meetings[i] = {end[i], start[i]};  
        }

       
        sort(meetings.begin(), meetings.end());

        int count = 1; 
        int lastEndTime = meetings[0].first;

        for (int i = 1; i < n; ++i) {
            if (meetings[i].second > lastEndTime) {
                count++;
                lastEndTime = meetings[i].first;
            }
        }

        return count;
    }
};
