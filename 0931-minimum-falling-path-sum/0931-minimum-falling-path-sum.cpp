class Solution {
public:
    int rec(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        int n=matrix.size();
        
        if(j>=n || j<0){
            return 1e9;
        }
        
        if(i==n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // if(i+1<n && j+1<n && j-1>=0)
        return dp[i][j]=matrix[i][j]+min({rec(i+1,j+1,matrix,dp),rec(i+1,j-1,matrix,dp),rec(i+1,j,matrix,dp)});
        
    }
    int tab(vector<vector<int>>& matrix){
        int n=matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                        // if(i+1<n && j+1<n && j-1>=0)
            int down=dp[i+1][j];
            int left=(j>0) ? dp[i+1][j-1] :1e9;
            int right=(j<n-1) ? dp[i+1][j+1] : 1e9;

            dp[i][j]=matrix[i][j]+min({down,left,right});
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int ans=1e9;

        vector<vector<int>>dp(m,vector<int>(m,-1));
        return tab(matrix);
        
        
        
    }
};