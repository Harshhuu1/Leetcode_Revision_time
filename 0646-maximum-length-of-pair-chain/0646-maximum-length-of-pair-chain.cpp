class Solution {
public:
    int solve(int i , int prevlast , vector<vector<int>>& pairs,vector<vector<int>> &dp){
        if(i>=pairs.size()){
            return 0;
        }
        if(dp[i][prevlast+1]!=-1)
        {
            return dp[i][prevlast+1];
        }
        int take=0;
        if(prevlast==-1 || pairs[i][0] > pairs[prevlast][1]){
            take =1+ solve(i+1 ,i , pairs,dp); 
        }
        int skip = solve(i+1 , prevlast , pairs,dp);
        return dp[i][prevlast+1]=max(take,skip);
    }

    int tab(vector<vector<int>>& pairs){
        int n = pairs.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prevlast=n-1;prevlast>=-1;prevlast--){
                int take=0;
                if(prevlast==-1 || pairs[i][0] > pairs[prevlast][1]){
                    take =1+ dp[i+1][i+1]; 
                }
                int skip = dp[i+1][prevlast+1];
                dp[i][prevlast+1]=max(take,skip);
            }
        }
        return dp[0][0];
    }
    int space(vector<vector<int>>& pairs){
        int n=pairs.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || pairs[i][0] > pairs[prev][1]){
                    take =1+ next[i+1]; 
                }
                int skip = next[prev+1];
                curr[prev+1]=max(take,skip);

            }
            next=curr;
        }
        return next[0];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        int m=pairs[0].size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(pairs.begin(),pairs.end());
        return space(pairs);
    }
};