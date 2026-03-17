class Solution {
public:
    int rec(int i , int j , vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(i>= n || j >= m)
        return 0;
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i == n-1 && j == m-1){
            return 1;
        }

        return dp[i][j]=rec(i+1 ,j ,obstacleGrid,dp)+rec(i, j+1,obstacleGrid,dp);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n , vector<int>(m,-1));
        return rec(0,0,obstacleGrid,dp);
    }
};