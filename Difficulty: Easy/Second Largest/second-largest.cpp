class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0];
        
        for(int i =1; i< n; i++){
            if(arr[i] > largest){
                largest = arr[i];
            }
        } 
        
        int slargest = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(arr[i] > slargest && arr[i] != largest){
                slargest = arr[i];
            }
        }
        
        return slargest;
    }
};