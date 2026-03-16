class Solution {
public:
    int lis(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n+1,1);
        vector<int>count(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1==dp[i]){
                        // dp[i]+=1;
                        count[i]+=count[j];
                    }
                    else if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }

                }
            }
        }
        int maxi=*max_element(dp.begin(),dp.end());
        int rcount=0;
        for(int i=0;i<n;i++)
        {
            if(maxi==dp[i]){
                rcount+=count[i];
            }
        }
        return rcount;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return lis(nums);
    }
};