class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        
         d = d%n;
        //temp
        
        vector<int> temp;
        
        for(int i=0; i<d; i++){
            temp.push_back(arr[i]);
        }
        
        //shifting
        
        for(int i =d; i<n; i++){
            arr[i-d] = arr[i];
        }
        
        //put back temp
        
        for(int i = n-d; i<n; i++){
            arr[i] = temp[i-(n-d)];
        }
    }
};