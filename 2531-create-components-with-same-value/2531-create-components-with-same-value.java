class Solution {
    private List<Integer>[] graph; 
    private int[] nodeValues;     
    private int targetValue;      

    
    public int componentValue(int[] nums, int[][] edges) {
        int n = nums.length;
        graph = new List[n];
        this.nodeValues = nums;
        Arrays.setAll(graph, k -> new ArrayList<>());
     
        for (int[] edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from].add(to);
            graph[to].add(from);
        }
      
      
        int sum = sum(nodeValues), max = max(nodeValues);

       
        for (int k = Math.min(n, sum / max); k > 1; --k) {
            if (sum % k == 0) { 
                targetValue = sum / k; 
               
                if (dfs(0, -1) == 0) {
                    return k - 1; 
                }
            }
        }
        // If no partition is found, return 0
        return 0;
    }

    // DFS function to explore graph and validate components
    private int dfs(int currentNode, int parent) {
        int currentValue = nodeValues[currentNode];
        for (int neighbor : graph[currentNode]) {
            if (neighbor != parent) {
                int subtreeValueSum = dfs(neighbor, currentNode);
                // If a subtree cannot form a component, propagate -1 up
                if (subtreeValueSum == -1) {
                    return -1;
                }
                currentValue += subtreeValueSum;
            }
        }
        // If the current sum exceeds target, return -1 indicating failure
        if (currentValue > targetValue) {
            return -1;
        }
        // If the current sum equals target, we can form a component (return 0)
        // Otherwise, return the current sum for further evaluation in the parent node
        return currentValue == targetValue ? 0 : currentValue;
    }

    // Utility method to calculate the sum of an array
    private int sum(int[] arr) {
        int totalSum = 0;
        for (int value : arr) {
            totalSum += value;
        }
        return totalSum;
    }

    // Utility method to find the maximum value in an array
    private int max(int[] arr) {
        int maxValue = arr[0];
        for (int value : arr) {
            maxValue = Math.max(maxValue, value);
        }
        return maxValue;
    }
}
