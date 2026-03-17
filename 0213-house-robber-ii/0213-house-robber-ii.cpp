class Solution {
public:
    int rec(int i, vector<int>& nums,vector<int>&dp){
        if(i>=nums.size())
        return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int take=-1;
        int skip=rec(i+1,nums,dp);
        take=nums[i]+rec(i+2,nums,dp);
        return dp[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>for1;
        vector<int>back1;
        int n=nums.size();
        vector<int>dp(n,-1);
        for(int i=1;i<n;i++){
            for1.push_back(nums[i]);


        }
        for(int i=0;i<n-1;i++){
            back1.push_back(nums[i]);
        }
                vector<int>dp1(n,-1); 
                vector<int>dp2(n,-1);



        return max(rec(0,back1,dp1),rec(0,for1,dp2));
    }
};