class Solution {
public:
    int solve(int i, int j1, int j2,vector<vector<int>>& grid ){
        int n=grid.size();
        int m=grid[0].size();
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
            return -1e9;
        }
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else 
            return grid[i][j1]+grid[i][j2];
        }
        int ans=-1e9;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
               int curr=0;
               if(j1==j2){
                curr= grid[i][j1];
            }
            else 
            curr= grid[i][j1]+grid[i][j2];
               curr+=solve(i+1,j1+dj1,j2+dj2,grid); 
               ans=max(ans,curr);
            }

        }
        return ans;
    }
    int tab(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                
                if(j1==j2){
                    dp[n-1][j1][j2]=grid[n-1][j1];
                }else
                dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                int ans=-1e9;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){

        
                    int curr=0;
                    if(j1==j2){
                        curr= grid[i][j1];
                    }
                    else 
                curr= grid[i][j1]+grid[i][j2];
                int nj1=j1+dj1;
                int nj2=j2+dj2;
            if(nj1 >=0 && nj1 < m && nj2 >= 0 && nj2 < m){
                curr+=dp[i+1][nj1][nj2]; 
                }
                else
                curr+=-1e9;

                ans=max(ans,curr);
            }

        }
        dp[i][j1][j2]=ans;
        
    }
                }
            }
        return dp[0][0][m-1];
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid[0].size();
        // return solve(0,0,m-1,grid);
        return tab(grid);
    }
};