class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& triangle,vector<vector<int>> &dp){
        int n=triangle.size();
        if(i>=n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=1e9;
        down=rec(i+1,j,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(rec(i+1,j+1,triangle,dp),down);


    }
    int tab(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                
        int down=1e9;
        
        
        if(i+1<n && j+1<n)
        dp[i][j]=triangle[i][j]+min(dp[i+1][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return rec(0,0,triangle,dp);
        return tab(triangle);
    }
};