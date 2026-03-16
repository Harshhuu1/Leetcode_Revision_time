class Solution {
public:
    int solve(int i,int j,int n,vector<int>& cuts){
        if(i>j){
            return 0;
        }
        int mini=1e9;
        for(int k=i;k<=j;k++){
            int steps=(cuts[j+1]-cuts[i-1])+solve(i,k-1,n,cuts)+solve(k+1,j,n,cuts);
            mini=min(mini,steps);
        }
        return mini;
    }
    int tab(vector<int>& cuts){
        int n=cuts.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-2;i>=1;i--)
        {
            for(int j=i;j<=n-2;j++){
                int mini=1e9;
                for(int k=i;k<=j;k++){
            int steps=(cuts[j+1]-cuts[i-1])+dp[i][k-1]+dp[k+1][j];
            mini=min(mini,steps);
        }
        dp[i][j]= mini;
            }
        }
        return dp[1][n-2];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts),end(cuts));
        int c=cuts.size();
        return tab(cuts);
        
    }
};