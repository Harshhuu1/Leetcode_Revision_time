1class Solution {
2public:
3    vector<vector<int>> fourSum(vector<int>& nums, int target) {
4        sort(nums.begin(),nums.end());
5        vector<vector<int>> ans;
6        
7        for(int i=0;i<nums.size();i++){
8                if(i>0 && nums[i]==nums[i-1]) continue;
9            for(int j=i+1;j<nums.size();j++){
10                if(j>i+1 && nums[j]==nums[j-1]) continue;
11                int left=j+1;
12                int right=nums.size()-1;
13               
14            while(left<right){
15                 long long  sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
16                if(sum==target){
17                    ans.push_back({nums[i],nums[j],nums[left],nums[right]});
18                    left++;
19                    right--;
20                    while(left<right && nums[left]==nums[left-1]) left++;
21                    while(left<right && nums[right]==nums[right+1]) right--;
22
23
24                }
25                else if(sum>target){
26                    right--;
27                }
28                else
29                 left++;
30            }
31            }
32        }
33        return ans;
34    }
35};