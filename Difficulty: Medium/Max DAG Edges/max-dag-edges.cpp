class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        long long max_possible_edges = (long long)V * (V - 1) / 2;
        
        int existing_edges = edges.size();
        
        return max_possible_edges - existing_edges;
    }
};