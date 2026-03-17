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
    int tab(vector<vector<int>>& obstacleGrid){
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<long long >>dp(n , vector<long long>(m,0));
        if(obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        dp[n-1][m-1]=1;
        for(int i =n-1 ; i>=0; i--){
            for(int j = m-1 ; j>=0 ; j--){
                if( i==n-1 && j== m-1)
                    continue;
                
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                long long down=0,right=0;
                 if(i+1 < n) down = dp[i+1][j];
            if(j+1 < m) right = dp[i][j+1];

            dp[i][j] = down + right;
            }
        }
        return dp[0][0];


    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty())
        return 0;

        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        // vector<vector<int>>dp(n , vector<int>(m,-1));
        // return rec(0,0,obstacleGrid,dp);
        return tab(obstacleGrid);
    }
};