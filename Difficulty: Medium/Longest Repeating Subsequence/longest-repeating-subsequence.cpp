class Solution {
 public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    string t=str;
		    
		    vector<vector<int>>dp(n+1,vector<int> (n+1,0));
		    
	for(int i=1;i<n+1;i++)
	{
	    for(int j=1;j<n+1;j++)
	    {
	        
	        if(str[i-1]==t[j-1] && i!=j)
	        {
	            dp[i][j]=1+dp[i-1][j-1];
	        }
	        else
	        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	        
	        
	    }
	}
		    
		return dp[n][n];
		}

};