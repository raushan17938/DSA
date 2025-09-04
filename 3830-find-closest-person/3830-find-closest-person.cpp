class Solution {
public:
    
    int findClosest(int x, int y, int z) {
        int distanceFromX = abs(x - z);
      
        int distanceFromY = abs(y - z);
      
        
        if (distanceFromX == distanceFromY) {
            return 0;  
        } else if (distanceFromX < distanceFromY) {
            return 1;  
        } else {
            return 2;  
        }
    }
};