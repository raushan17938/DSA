class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        
        long long totalMoves = 0;
        int n = chairs.size();
        
        for (int i = 0; i < n; i++) {
            totalMoves += abs(chairs[i] - passengers[i]);
        }
        
        return (int)totalMoves;
    }
};