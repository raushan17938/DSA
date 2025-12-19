class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knowsSecret(n);
        knowsSecret[0] = true;           
        knowsSecret[firstPerson] = true; 
      
        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
      
        int totalMeetings = meetings.size();
        int currentIndex = 0;
      
        while (currentIndex < totalMeetings) {
            int endIndex = currentIndex;
            while (endIndex + 1 < totalMeetings && 
                   meetings[endIndex + 1][2] == meetings[currentIndex][2]) {
                endIndex++;
            }
          
            unordered_map<int, vector<int>> adjacencyList;
            unordered_set<int> peopleInCurrentTime;
          
            for (int k = currentIndex; k <= endIndex; k++) {
                int person1 = meetings[k][0];
                int person2 = meetings[k][1];
              
                adjacencyList[person1].push_back(person2);
                adjacencyList[person2].push_back(person1);
                peopleInCurrentTime.insert(person1);
                peopleInCurrentTime.insert(person2);
            }
          
            queue<int> bfsQueue;
          
            for (int person : peopleInCurrentTime) {
                if (knowsSecret[person]) {
                    bfsQueue.push(person);
                }
            }
          
            while (!bfsQueue.empty()) {
                int currentPerson = bfsQueue.front();
                bfsQueue.pop();
              
                for (int neighbor : adjacencyList[currentPerson]) {
                    if (!knowsSecret[neighbor]) {
                        knowsSecret[neighbor] = true;
                        bfsQueue.push(neighbor);
                    }
                }
            }
          
            currentIndex = endIndex + 1;
        }
      
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knowsSecret[i]) {
                result.push_back(i);
            }
        }
      
        return result;
    }
};
